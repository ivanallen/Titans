#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFERSIZE 1024
int main(int argc, char* argv[]) {
    int len, srcfd, dstfd;
    char buffer[BUFFERSIZE] = {0};

    if (argc < 3) {//检查命令有几个部分，是否够3部分
        printf("Command error!\n");
        return -1;
    }

    if ((srcfd = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }

    if ((dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666)) == -1) {
        perror("open");
        close(srcfd);
        return -1;
    }

    while ((len = read(srcfd, buffer, BUFFERSIZE)) > 0) {
        if (write(dstfd, buffer, len) != len) {
            perror("write");
            return -1;
        }   
    }

    if (len < 0) {
        perror("read");
        return -1;
    }

    close(srcfd); 
    close(dstfd);
    return 0;
}
