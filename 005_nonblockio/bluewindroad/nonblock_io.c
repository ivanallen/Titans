#define _POSIX_C_SOURCE 201906L

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>
#include <errno.h>

#define MAX_FILE 10

char* upper(char* str, int n) {
    assert(str != NULL);
    for (int i = 0; i < n; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 'a' - 'A';
    }
    return str;
}

int set_nonblock(int fd) {
    int old = fcntl(fd, F_GETFL);
    return fcntl(fd, F_SETFL, old | O_NONBLOCK);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        return 1;
    }

    int fd[MAX_FILE];
    for (int i = 0; i < MAX_FILE; ++i) fd[i] = -1;

    for (int i = 0; i < MAX_FILE && i < argc - 1; ++i) {
        fd[i] = open(argv[i+1], O_RDONLY);
        if (set_nonblock(fd[i]) == -1) {
            perror("set_nonblock");
        }
        if (fd[i] < 0) {
            perror("open");
        }
    }

    // cacheline 一般为 64 字节
    char buf[64] = { 0 };
    int len = 0;

    while (1) {
        int stop = 1;
        for (int i = 0; i < MAX_FILE; ++i) {
            if (fd[i] == -1) continue;
            stop = 0;
            len = read(fd[i], buf, 64);
            if (len < 0) {
                if (errno == EAGAIN || errno == EWOULDBLOCK) ;
                else perror("read");
                continue;
            }

            if (len == 0) {
                dprintf(STDOUT_FILENO, "%d > EOF\n", i);
                close(fd[i]);
                fd[i] = -1;
                continue;
            }
            dprintf(STDOUT_FILENO, "%d > ", i);
            write(STDOUT_FILENO, upper(buf, len), len);
        }
        if (stop) break;
    }
    return 0;
}
