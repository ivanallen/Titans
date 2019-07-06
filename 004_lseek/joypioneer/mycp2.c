#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h> 

#define BUFSIZE 1024
int main(int argc, char* argv[]) {
    char buf[BUFSIZE] = {0};
    int srcfd = -1, dstfd = -1, len = 0;

    if (argc < 3) {
        printf("Usage: mycp2 SOURCE DEST\n");
        return -1;
    }
    srcfd = open(argv[1], O_RDONLY);
    if (-1 == srcfd) {
        printf("[%s] open failed!\n", argv[1]);
        return -1;
    }
    int tmpfd = dup(srcfd);
    if (-1 == tmpfd) {
        perror("dup error");
        close(srcfd);
        return -1;
    }
    close(tmpfd);
    int src_file_size = lseek(srcfd, 0, SEEK_END);
    if (-1 == src_file_size) {
        close(srcfd);
        perror("get file size!");
        return -1;
    }
    int pos = lseek(srcfd, src_file_size/2,  SEEK_SET);
    if (-1 == pos) {
        close(srcfd);
        perror("set file pos!");
        return -1;
    }
    dstfd = open(argv[2], O_WRONLY|O_CREAT, 0666);
    if (-1 == dstfd) {
        printf("[%s] open failed!\n", argv[2]);
        close(srcfd);
        return -1;
    }
    while ((len = read(srcfd, buf, BUFSIZE)) > 0) {
        if (write(dstfd, buf, len) != len) {
            perror("write error");
            close(srcfd);
            close(dstfd);
            return -1;
        }
    }
    if (len < 0)
        perror("read error");
    close(srcfd);
    close(dstfd);
    return 0;
}
