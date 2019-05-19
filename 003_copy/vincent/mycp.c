#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFSIZE 1024
int main(int argc, char* argv[])
{
    char            buf[BUFSIZE];
    int             cnt;
    int             fdIn, fdOut;

    if (argc < 3) {
        printf("Usage: mycp SOURCE DEST\n");   
        return -1;
    }

    if ((fdIn = open(argv[1], O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }

    if ((fdOut = open(argv[2], O_WRONLY|O_CREAT, 0666)) < 0) {
        perror("open");
        return -1;
    }

    while ((cnt = read(fdIn, buf, BUFSIZE)) > 0) {
        if(write(fdOut, buf, cnt) != cnt) {
            perror("write");
        }
    } 

    close(fdIn);
    close(fdOut);
    return 0;
}