#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

#define BUFSIZE 4096

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("usage:\n mycp2 sour des\n");
        return -1;
    }
    int sourfd = open(argv[1], O_RDONLY);
    if (sourfd == -1) {
        perror("open source file");
        return -1;
    }
    int desfd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (desfd == -1) {
        perror("open destination file");
        return -1;
    }
    
    int filelen = lseek(sourfd, 0, SEEK_END);
    int cur_pos = lseek(sourfd, filelen/2, SEEK_SET);
    
    char buf[BUFSIZE] = {0};
    int len = 0;
    while ((len = read(sourfd, buf, BUFSIZE)) > 0) {
        if (write(desfd, buf, len) != len) {
            perror("write error");
            return -1;
        }
    }
    if (len < 0) {
        perror("read error");
        return -1;
    }
    close(sourfd);
    close(desfd);
    return 0;
}
