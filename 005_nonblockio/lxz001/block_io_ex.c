#define _POSIX_C_SOURCE 201906L

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

#define FILE_MAX 10

char* upper(char* str, int n) {
    assert(str != NULL);
    for (int i = 0; i < n; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 'a' - 'A';
    }
    return str;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }

    int fd[FILE_MAX];
    for (int n = 0; n < FILE_MAX; ++n) fd[n] = -1;
    for (int n = 0; n < FILE_MAX && n < argc - 1; ++n) {
        fd[n] = open(argv[n + 1], O_RDONLY);
        if (fd[n] == -1) {
            perror("open");    
        }
    }    

    // cacheline 一般为 64 字节
    char buf[64] = { 0 };
    int len = 0;

    while (1) {
        short stop = 1;
        for (int n = 0; n < FILE_MAX && n < argc - 1; ++n) {
            if (fd[n] == -1) {
                continue;
            } 
            stop = 0;
            len = read(fd[n], buf, 64);
            if (len < 0) {
                perror("read");
                continue;
            }   

            if (len == 0) {
                dprintf(STDOUT_FILENO, "%d > EOF\n", n);
                close(fd[n]);
                fd[n] = -1;
                continue;
            }
            dprintf(STDOUT_FILENO, "%d > ", n);
            write(STDOUT_FILENO, upper(buf, len), len);
        }
        if (stop) break;
    }
    return 0;
}
