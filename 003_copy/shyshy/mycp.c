#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFERSIZE 1024

int main(int argc, char* argv[]){

    char buf[BUFFERSIZE];
    int srcfd = open(argv[1], O_RDONLY);
    int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);

    if (argc < 3) {
        printf("Usage: mycp SOURCE DEST\n");   
        return -1;
    }

    if(srcfd < 0){
        perror("open error");
        return -1;
    }

    if(dstfd < 0){
        perror("open error");
        close(srcfd);
        return -1;
    }

    int count;
    while ((count = read(srcfd, buf, BUFFERSIZE)) > 0){
        if (write(dstfd, buf, count) != count){
            perror("write error");
            close(srcfd);
            close(dstfd);
            return -1;
        }
    }
    if (count < 0){
        perror("write error");
        return -1;
    }
    close(srcfd);
    close(dstfd);
    return 0;
}



