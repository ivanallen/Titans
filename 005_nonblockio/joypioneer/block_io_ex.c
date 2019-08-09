#define _POSIX_C_SOURCE 201906L

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

#define FILE_MAX 4

static char *upper(char* str, int len) {
    if (str == NULL) return NULL;

    int i = 0;
    for (; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 'a' - 'A';
    }
    return str;
}

int main(int argc, char* argv[]) {
    if (argc < 2) return -1;

    int i, openFileCnt = 0, fd[FILE_MAX];
    for (i = 0; i < FILE_MAX && i < argc - 1; i++) {
        fd[i] = open(argv[i + 1], O_RDONLY);
        if (fd[i] == -1) {
            perror("open");
            continue;
        }
        openFileCnt ++;
    }    
    // cacheline 一般为 64 字节
    char buf[64] = { 0 };
    int len = 0;

    while (1) {
        for (i = 0; i < FILE_MAX && i < argc - 1; i++) {
            if (fd[i] == -1) {
                continue;
            }
            len = read(fd[i], buf, 64);
            if (len < 0) {
                perror("read");
            } else if (len == 0) {
                printf("%d  EOF\n", i);
                close(fd[i]);
                fd[i] = -1;
                openFileCnt --;
            } else {
                printf("%d >>>> ", i);
                write(STDOUT_FILENO, upper(buf, len), len);
            }
        }
        if (openFileCnt == 0) break;
    }
    return 0;
}
