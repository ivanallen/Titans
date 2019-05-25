#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFERSIZE 4096

int main(int argc, char* argv[]) {
    char buf[BUFFERSIZE];
    int len, srcfd, dstfd;

    if(argc != 3) {
        printf("usage: mycp SOURCE DEST\n");
        return 1;
    }

    if((srcfd = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        return 1;
    }

    if((dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666)) == -1) {
        perror("open");
        return 1;
    }

    while((len = read(srcfd, buf, BUFFERSIZE)) > 0) {
        if(write(dstfd, buf, len) != len) {
            perror("write");
            return 1;
        }
    }
    if(len < 0) {
        perror("write");
        return 1;
    }

    close(srcfd);
    close(dstfd);
    return 0;
}
