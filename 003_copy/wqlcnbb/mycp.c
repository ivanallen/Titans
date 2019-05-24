#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFERSIZE 1024

int main(int argc, char* argv[]){
    if(3 != argc){
        printf("Usage: mycp src det!\n");
        return -1;
    }
    int srcfd = open(argv[1], O_RDONLY);
    if (-1 == srcfd){
        perror("open error");
        return -1;
    }
    
    int dstfd = open(argv[2], O_CREAT|O_WRONLY, 0666);
    if(-1 == dstfd){
        perror("open error");
        return -1;
    }
    
    char buf[BUFFERSIZE] = {0};
    int count = 0;
    
    while((count = read(srcfd, buf, BUFFERSIZE)) > 0){
        if(write(dstfd, buf, count) != count){
            perror("write error");
            return -1;
        }
    }
    
    if(count < 0){
        perror("read error");
        return -1;
    }

    close(srcfd);
    close(dstfd);
    return 0;
}
