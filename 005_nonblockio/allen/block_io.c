#define _POSIX_C_SOURCE 201906L

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

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

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 2;
    }

    // cacheline 一般为 64 字节
    char buf[64] = { 0 };
    int len = 0;
    int ret = 0;

    while (1) {
        len = read(fd, buf, 64);
        if (len < 0) {
            perror("read");
            ret = 3;
            break;
        }

        if (len == 0) {
            write(STDOUT_FILENO, "EOF\n", 4);
            ret = 0;
            break;
        }
        write(STDOUT_FILENO, upper(buf, len), len);
    }

    close(fd);
    return ret;
}
