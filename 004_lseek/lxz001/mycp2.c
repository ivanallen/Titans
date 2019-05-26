#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

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
    struct stat file_stat;
    if (fstat(f1, &file_stat) < 0){
        perror("malloc stat error!");
        return 1;
    }
    if (lseek(f1, file_stat.st_size / 2, SEEK_SET) < 0){
        perror("lseek error!");
        return 1;
    }
    const int BUF_SIZE = 1024;
    char buf[BUF_SIZE];
    int read_size;
    do {
        read_size = read(f1, buf, BUF_SIZE);
        if (read_size < 0){
            perror("read error!");
            return 1; 
        }
        if (write(f2, buf, read_size) < 0){
            perror("write error!");
            return 1;
        }
    } while (read_size > 0);
    close(f1);
    close(f2);
    return 0;
}
