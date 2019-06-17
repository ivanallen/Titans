#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("arg error!\n");
        return -1;
    }
    int srcfd = open(argv[1], O_RDONLY);
    if (srcfd == -1) {
        perror("open");
        return -1;
    }

    int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (dstfd == -1) {
        close(srcfd);
        perror("open");
        return -1;
    }

    int size = lseek(srcfd, 0, SEEK_END);
    int midpos = size / 2;
    lseek(srcfd, midpos, SEEK_SET);

    int len;
    char * buf = (char*)malloc(size - midpos);

    while((len = read(srcfd, buf, size - midpos)) > 0) {
        if (write(dstfd, buf, len) != len) {
            perror("write error");
            free(buf);
            return -1;
        }   
    }
    if (len < 0) {
        perror("read error");
        free(buf);
        return -1;
    }

    free(buf);
    close(srcfd);
    close(dstfd);
    return 0;
}
