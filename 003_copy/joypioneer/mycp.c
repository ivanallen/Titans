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
        printf("Usage: mycp SOURCE DEST\n");
        return -1;
    }
    srcfd = open(argv[1], O_RDONLY);
    if (srcfd < 0) {
        printf("[%s] open failed!\n", argv[1]);
        return -1;
    }
    dstfd = open(argv[2], O_WRONLY|O_CREAT, 0666);
    if (dstfd < 0) {
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
