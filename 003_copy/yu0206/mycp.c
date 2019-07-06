#include <unistd.h>
#include <bits/types.h> //基本系统数据类型
#include <sys/stat.h> //stat文件全部属性
#include <fcntl.h>
#include <stdio.h>

#define BFSIZE 1024

int main(int arg, char *argv[]) {
    if(arg != 3) {
        perror("Error arg");
        return -1;
    }

    int oldfd = open(argv[1], O_RDONLY);
    if(oldfd == -1) {
        perror("Error open");
        return -1;
    }

    int newfd = open(argv[2], O_WRONLY|O_CREAT, 0666);
    if(newfd == -1) {
        perror("Error creat");
        return -1;
    }

    char buffer[BFSIZE] = { 0 };
    int rlength = 0;
    int wlength = 0;

    while(1) {
        rlength = read(oldfd, buffer, BFSIZE);
        if(rlength == 0) {
            break;
        }else if(rlength == -1) {
            perror("Error read");
            close(oldfd);
            close(newfd);
            return -1;
        }

        wlength = write(newfd, buffer, rlength); //应该写入长度为rlength的字节 因为最后一次读取可能rlength < BFSIZE
        if(wlength != rlength) {
            perror("Error write");
            close(oldfd);
            close(newfd);
            return -1;
        }
    }
    close(oldfd);
    close(newfd);
    return 0;
}
