#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#define MAXSIZE 4096

int main(int argc, char* argv[]){
    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
    printf("Error : reading the file\n");
    perror("Error ");
    return -1;
}
    int dst = open(argv[2], O_WRONLY|O_CREAT, 0666);
    if (dst == -1) {
    printf("Error : creating the file\n");
    perror("Error");
    close(src);
    return -1;
}
    char buffer[MAXSIZE] = "";
    int len = 0;
    while ((len = read(src, buffer, MAXSIZE)) > 0){
    if (write(dst, buffer, len) != len){
        perror("Error copying file!\n");
        break;
    }
}
    if (len == 0)
    printf("End copy!\n");
    else if (len < 0)
    perror("read file error!\n");
    close(dst);
    close(src);
    return 0;
}
