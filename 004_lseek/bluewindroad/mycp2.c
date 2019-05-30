#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
int main(int argc, char *filename[]) {
    if (argc != 3) {
       printf("usage:\n mycp src dst\n");
       return -1;
    }
    int becopy = open(filename[1], O_RDONLY);
    if (becopy == -1) {
        perror("open becopy");
        return -1;
    }
    int copyto = open(filename[2], O_CREAT | O_WRONLY);
    if (copyto == -1) {
        perror("open copyto");
        return -1;
    }
    int ret = lseek(becopy, 0, SEEK_END);
    if (ret == -1) {
        perror("lseek first wrong");
        return -1;
    }
    ret = lseek(becopy, ret/2, SEEK_SET);
    if (ret == -1) {
        perror("lseek second wrong");
        return -1;
    }
    char buffer[4096] = {0};
    int length = 0;
    while ((length = read(becopy, buffer, 4096))>0) {
        if (write(copyto, buffer, length) != length) {
            perror("write error");
            return -1;
        }
    }
    if (length < 0) {
        perror("read error");
        return -1;
    }
    ret = lseek(becopy, 0, SEEK_END);
    printf("becopyfilesize:%d\n", ret);
    ret = lseek(copyto, 0, SEEK_END);
    printf("becopyfilesize:%d\n", ret);
    close(becopy);
    close(copyto);
    return 0;
}
