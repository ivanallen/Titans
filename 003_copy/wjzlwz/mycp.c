#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFERSIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("wrong format");
        return -1;
    }
    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror("open error");
        return -1;
    }

    int dst = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (dst == -1) {
        perror("open error");
        return -1;
    }

    int length  = 0;
    char buffer[BUFFERSIZE] = {0};

    while((length = read(src, buffer, BUFFERSIZE)) > 0) {
        if (write(dst, buffer, length) != length) {
            perror("write error");
            return -1;
        }   
    }
    if (length < 0) {
        perror("read error");
        return 1;
    }
    close(src); // 关闭文件
    close(dst);
    return 0;
}
