#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFERSIZE 4096

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("usage:\n mycp2 src dst\n");
        return -1;
    }

    int srcfd = open(argv[1], O_RDONLY);
    if (srcfd == -1) {
        perror("open:");
        return -1;
    }

    int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (dstfd == -1) {
        perror("open:");
        return -1;
    }

    int file_length = lseek(srcfd, 0, SEEK_END);
    if (-1 == file_length) {
        close(srcfd);
        perror("get file_length error\n");
        return -1;
     }
    int pos = lseek(srcfd, file_length / 2, SEEK_SET);
    if (-1 == pos) {
        close(srcfd);
        perror("lseek error\n");
        return -1;
    } 

    int len = 0;
    char buffer[BUFFERSIZE] = {0};

    while((len = read(srcfd, buffer, BUFFERSIZE)) > 0){
        if (write(dstfd, buffer, len) != len) {
            perror("write:");
            return -1;
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
