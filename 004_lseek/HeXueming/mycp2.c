
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFERSIZE 4096

int file_size (char* filename) {

    struct stat statbuf;
    stat(filename, &statbuf);
    int size = statbuf.st_size;
 
    return size;
}

int main (int argc, char* argv[]) {
	if (argc != 3) {
        printf("usage:\n mycp src dst \n");
        return 1;
    }
    int srcfd = open(argv[1], O_RDONLY);
    if (srcfd == -1) {
        perror("open");
        return 1;
    }

    int dstfd = open(argv[2], O_CREAT |  O_WRONLY, 0666);
    if (dstfd == -1) {
        perror("open");
        return 1;
    }

    int len = 0;
    char buffer[BUFFERSIZE] = {0};

    int fileSize = file_size("test.txt");//test.txt是复制的源文件
    off_t curr = lseek(srcfd, fileSize>>1, SEEK_SET);

    while ((len = read(srcfd, buffer, BUFFERSIZE)) > 0) {
        if (write(dstfd, buffer, len) != len) {
            perror("write error");
            return 1;		
        }
    }
    if (len < 0) {
        perror("read error");
    }
    close(srcfd);
    close(dstfd);
    return 0;
}