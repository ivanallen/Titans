#include<stdio.h>
#include<unistd.h>
#include<ctype.h>
//#include<sys/stat.h>
#include<fcntl.h>
#define MAX_OPEN_FILE 3
#define MAX_BUF_LEN 64
char *upper(char* str, int len);

int main(int argc, char* argv[])
{
    if (argc < 2 || argc - 1 > MAX_OPEN_FILE) {
        return -1;
    }
    
    int i, opening_file_cnts = 0, fd[MAX_OPEN_FILE];
    for (i = 0; i < argc - 1; i++) {
        fd[i] = open(argv[i + 1], O_RDONLY);
        if (fd[i] < 0) {
            perror("open");
            continue;
        }
        opening_file_cnts++;
    }

    char buf[MAX_BUF_LEN] = {0};
    int len = 0;
    while(1) {
        for (i = 0; i < argc - 1; i++) {
            if (fd[i] < 0) {
                continue;
            }
            len = read(fd[i], buf, MAX_BUF_LEN);
            if (len < 0) {
                perror("read");
            } else if (len == 0) {
                printf("%d END\n", i);
                close(fd[i]);
                opening_file_cnts--;
                fd[i] = -1;
            } else {
                printf("%d > ", i);
                fflush(stdout);
                write(STDOUT_FILENO, upper(buf, len), len);
                //printf("%d > %s", i, upper(buf, len));
            }
        }
        if (opening_file_cnts == 0) {
            break;
        }
    }

    return 0;
}

char *upper(char* str, int len)
{
    if (str == NULL) {
        return str;
    }

    int i;
    for (i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}
