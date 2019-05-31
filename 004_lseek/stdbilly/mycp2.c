#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFERSIZE 4096

int main(int argc, char** argv) {
    char buf[BUFFERSIZE];
    int len, src_fd, dst_fd;

    if (argc != 3) {
        printf("usage: mycp2 SOURCE DEST\n");
        return 1;
    }
    
    if ((src_fd = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        return 1;
    }

    if ((dst_fd = open(argv[2], O_CREAT | O_WRONLY, 0666)) == -1) {
        perror("open");
        return 1;
    }

    int file_len = lseek(src_fd, 0, SEEK_END);
    int mid = file_len / 2;
    int pos = lseek(src_fd, mid, SEEK_SET);

    while((len = read(src_fd, buf, BUFFERSIZE)) > 0) {
        if(write(dst_fd, buf, len) != len) {
            perror("write error");
            return 1;
        }
    }
    if (len < 0) {
        perror("read error");
        return 1;
    }
    
    close(src_fd);
    close(dst_fd);
    return 0;
}
