#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <assert.h>
#define ARGS_CHECK(argc,val) {if(argc!=val)  {printf("error args\n");return -1;}}
#define ERROR_CHECK(ret,retVal,funcName) {if(ret==retVal) {perror(funcName);return -1;}}
#define MAX_FD 3

char* toUpper(char *str, int n) {
    assert(str !=NULL);
    for(int i = 0; i < n; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') 
            str[i] -= 32;
    }
    return str;
}

int set_nonblock(int fd) {
    int old = fcntl(fd, F_GETFL);
    return fcntl(fd, F_SETFL, old | O_NONBLOCK);
}

int main(int argc, char *argv[]) {
    ARGS_CHECK(argc, 3);
    int fd[MAX_FD];
    for (int i = 0; i < argc - 1; i++) {
        fd[i] = open(argv[i+1], O_RDONLY);
        ERROR_CHECK(fd[i],-1,"open");
        set_nonblock(fd[i]);
    }

    char buf[64] = { 0 };
    int len = 0;

    while(1) {
        int stop = 1;
        for (int i = 0; i < argc - 1; i++) {
            if (fd[i] == -1) continue;
            stop = 0;
            len = read(fd[i], buf, 64);
            if (len < 0) {
                if (errno == EAGAIN) sleep(1);
                continue;
            }

            if (len == 0) {
                printf("%d > EOF\n", i);
                close(fd[i]);
                fd[i] = -1;
                continue;
            }
            printf("%d > ", i);
            write(STDOUT_FILENO, toUpper(buf, len), len);
        }
        if(stop) break;
    }
    return 0;
}
