#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int srcfd = -1;//源文件描述符
    int dstfd = -1;//目标文件描述符
    char rwbuf[MAXSIZE] = {0};//读写数据的缓冲区
    size_t count = -1;//每次从文件中读取到的数据的实际字节数和写入文件的数据的实际字节数

    srcfd = open(argv[1], O_RDONLY);
    if (-1 == srcfd) {
        perror("Source file open error!\n");
        return -1;
    }

    dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (-1 == dstfd) {
        close(srcfd);
        perror("Destination file open error!\n");
        return -1;
    }

    while ((count = read(srcfd, rwbuf, MAXSIZE)) > 0) {
        if (write(dstfd, rwbuf, count) != count) {
            perror("Error copying file!\n");
            break;
        }
        memset(rwbuf, 0, sizeof(rwbuf));
    }

    if (count == 0) {
        printf("End of copy file!\n");
    } else if (count == -1) {
        perror("Read source file error!\n");
    }

    close(dstfd);
    close(srcfd);

    return 0;
}
