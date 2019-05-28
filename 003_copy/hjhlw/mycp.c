#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("your parameters are incorrect\n");
        return -1;
    }

    int src=open(argv[1], O_RDONLY);
    if (src == -1) {
        printf("Error : reading the file\n");
        perror("Error ");
        return -1;
    }
    int dst = open(argv[2], O_WRONLY|O_CREAT, 0666);
    if (dst == -1) {
        printf("Error : creating the file\n");
        perror("Error ");
        close(src);
        return -1;
    }

    char buf[BUFSIZ] = "";
    int count = 0;
    while (1) {
        count = read(src, buf, BUFSIZ);
        if(count == 0) break;
        else if (count == -1) {
            perror("Error ");
            break;    
        }
        else {
           count = write(dst, buf, count);
           if (count == -1) {
               perror("Error ");
               break;
           }
        }
    }
    close(src);
    close(dst);
    return 0;
}
