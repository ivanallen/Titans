#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFSIZE 1024
int main(int argc, char* argv[])
{
    char    buf[BUFSIZE];
    int     cnt, fd_in, fd_out;

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
        // Linux kernel will automatically closes opened files When the process end.
        // but it's a good programming practise to close the files explicitly
        close(fd_in); 
        return -1;
    }

    printf("fd_in = %d, fd_out = %d\n", fd_in, fd_out);
    
    while ((cnt = read(fd_in, buf, BUFSIZE)) > 0) {
        if(write(fd_out, buf, cnt) != cnt) {
            perror("write");
            close(fd_in);
            close(fd_out);
            return -1;
        }
    } 
    
    if (cnt < 0) {
        perror("read");
    }

    close(fd_in);
    close(fd_out);
    return 0;
}
