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
    off_t src_file_size = -1;//源文件大小，字节数
    off_t dst_file_size = -1;//目标文件代销，字节数
    off_t currpos = -1;//文件指针的当前位置的偏移量

    srcfd = open(argv[1], O_RDONLY);
    if (-1 == srcfd) {
        perror("Source file open error!\n");
        return -1;
    }

    src_file_size = lseek(srcfd, 0, SEEK_END);//获取源文件大小
    if (-1 == src_file_size) {
        close(srcfd);
        perror("Failed to get file size!\n");
        return -1;
    }

    currpos = lseek(srcfd, src_file_size/2,  SEEK_SET);//重新定位文件指针的偏移位置，文件指针指向文件的一半的位置。
    if (-1 == currpos) {
        close(srcfd);
        perror("File pointer positioning error!\n");
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
        dst_file_size = lseek(dstfd, 0, SEEK_END);//获取目标文件大小
        if (-1 == dst_file_size) {
            close(dstfd);
            close(srcfd);
            perror("Failed to get the destination file size!\n");
            return -1;
        }
        printf("End of copy file!\n");
        printf("Source file size : %ld\n", src_file_size);
        printf("Destination file size : %ld\n", dst_file_size);
        printf("The starting position of the source file read : %ld\n", currpos);

    } else if (count == -1) {
        perror("Read source file error!\n");
    }

    close(dstfd);
    close(srcfd);

    return 0;
}
