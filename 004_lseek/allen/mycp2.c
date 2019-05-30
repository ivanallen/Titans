#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFERSIZE 4096

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("usage:\n mycp2 src dst\n");
        return 1;
    }
    int srcfd = open(argv[1], O_RDONLY);
    if (srcfd == -1) {
        perror("open");
        return 1;
    }

    int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (dstfd == -1) {
        perror("open");
        return 1;
    }

    int file_length = lseek(srcfd, 0, SEEK_END);
    int mid = file_length / 2;
    int pos = lseek(srcfd, mid, SEEK_SET);

    int len  = 0;
    char buffer[BUFFERSIZE] = {0};

    while((len = read(srcfd, buffer, BUFFERSIZE)) > 0) {
        if (write(dstfd, buffer, len) != len) {
            perror("write error");
            return 1;
        }   
    }
    if (len < 0) {
        perror("read error");
        return 1;
    }
    close(srcfd);
    close(dstfd);
    return 0;
}
