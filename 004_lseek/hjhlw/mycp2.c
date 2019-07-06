#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("few parameters\n");
        return -1;
    }
    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror("open");
        return -1;
    }
    int des = open(argv[2], O_CREAT|O_WRONLY, 0666);
    if (des == -1) {
        perror("creat");
        close(src);
        return -1;
    }
    off_t length = lseek(src, 0, SEEK_END) - 1;
    
    if (length == -1) {
        perror("lseek");
        return -1;
    }
    off_t ol = lseek(src, length / 2, SEEK_SET);
    if (ol == -1) {
        perror("lseek");
        return -1;
    }
    char buf[BUFSIZ] = "";
    while (1) {
        int count = read(src, buf, BUFSIZ);
        if (count == -1) {
            perror("read");
            break;
        }
        if (count == 0) {
            break;
        }
        count = write(des, buf, count);
        if (count == -1) {
            perror("write");
            break;
        }

    }
    close(src);
    close(des);
    return 0;
}
