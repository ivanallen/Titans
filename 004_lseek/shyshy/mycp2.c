#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFERSIZE 1024

int main(int argc, const char* argv[]){
    char buf[BUFFERSIZE];
    int srcfd = open(argv[1], O_RDONLY);
    int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (argc < 3){
        printf("Usage: mycp2 SOURCE DEST\n");
        return -1;
    }
    if(srcfd < 0){
        perror("open error!\n");
        return -1;
    }
    if(dstfd < 0){
        perror("open error!\n");
        close(srcfd);
        return -1;
    }
    off_t src_len = lseek(srcfd, 0, SEEK_END);  // 获取源文件长度；
    off_t cur_pos = lseek(srcfd, src_len/2, SEEK_SET);  //让文件指针指向src_len/2处；
    int count;
    while((count = read(srcfd, buf, BUFFERSIZE)) > 0){
        if(write(dstfd, buf, count) != count){
            perror("write error!\n");
            close(srcfd);
            close(dstfd);
            return -1;
        }
    }
    if(count < -1){
        perror("write error!\n");
        return -1;
    }
    close(srcfd);
    close(dstfd);
    return 0;
}
