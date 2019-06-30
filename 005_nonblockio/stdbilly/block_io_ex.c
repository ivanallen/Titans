#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>
#define args_check(argc,val) do {if(argc!=val)  {printf("error args\n");}} while(0)
#define error_check(ret,retVal,funcName) do {if(ret==retVal) {perror(funcName);}} while(0)
#define MAX_FD 3 

char* to_upper(char *str, int n) {
    assert(str !=NULL);
    for(int i = 0; i < n; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') 
            str[i] -= 32;
    }
    return str;
}

int main(int argc, char* argv[]) {
    args_check(argc, 3);
    int fd[MAX_FD];
    for (int i = 0; i < argc - 1 && i < MAX_FD; i++) {
        fd[i] = open(argv[i+1], O_RDONLY);
        error_check(fd[i], -1, "open");
    }

    char buf[64] = {0};
    int len = 0;

    while(1) {
        int stop = 1;
        for (int i = 0; i < argc - 1; i++) {
            if (fd[i] == -1) continue;
            stop = 0;
            len = read(fd[i], buf, 64);
            error_check(len, -1, "read");

            if (len == 0) {
                dprintf(STDOUT_FILENO, "%d > EOF\n", i);
                close(fd[i]);
                fd[i] = -1;
                continue;
            }
            dprintf(STDOUT_FILENO, "%d > ", i);
            write(STDOUT_FILENO, to_upper(buf, len), len);
        }
        if(stop) break;
    }
    return 0;
}
