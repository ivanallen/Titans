#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define MAX 1024
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("parameter error\n");
        return -1;
    }
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("Source file open failed");
        return -1;
    }
    int dst_fd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (dst_fd == -1) {
        perror("Destination file open failed");
        return -1;
    }
    char buf[MAX];
    int count=0;
    while (1) {
        count = read(src_fd, buf, MAX);
        if (count == 0)
            break;
        else if (count < 0) {
            perror("read error");
            close(src_fd);
            close(dst_fd);
            return -1;
        }
        if (write(dst_fd, buf, count) != count) {
            perror("write error");
            close(src_fd);
            close(dst_fd);
            return -1;;
        }
    }
    close(src_fd);
    close(dst_fd);
    return 0;
}

