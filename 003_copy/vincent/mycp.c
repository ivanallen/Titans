#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFSIZE 1024
int main(int argc, char* argv[])
{
    char            buf[BUFSIZE];
    int             cnt;
    int             fd_in, fd_out;

    if (argc < 3) {
        printf("Usage: mycp SOURCE DEST\n");   
        return -1;
    }

    if ((fd_in = open(argv[1], O_RDONLY)) < 0) {
        perror("open");
        return -1;
    }

    if ((fd_out = open(argv[2], O_WRONLY|O_CREAT, 0666)) < 0) {
        perror("open");
        return -1;
    }

    while ((cnt = read(fd_in, buf, BUFSIZE)) > 0) {
        if(write(fd_out, buf, cnt) != cnt) {
            perror("write");
        }
    } 

    close(fd_in);
    close(fd_out);
    return 0;
}
