#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, const char * argv[]){
    if (argc != 3){
        perror("parameter error!");
        return 1;
    }
    int f1 = open(argv[1], O_RDONLY);
    int f2 = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (f1 == -1 || f2 == -1){
        perror("open error!");
        return 1;
    }
    char buf[BUFSIZE + 1];
    int r_size;
    do {
        r_size = read(f1, buf, BUFSIZE);
        if (r_size == -1){
            perror("read error!");
            return 1;
        } 
        if (write(f2, buf, r_size) != r_size){
            perror("write error!");
            return 1;
        }
    } while (r_size != 0);
    close(f1);
    close(f2);
    return 0;    
}
