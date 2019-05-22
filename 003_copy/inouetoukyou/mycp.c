#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFERSIZE 4096
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: mycp SOURCE DEST\n"
               "Copy SOURCE to DEST, only for files.\n");
        return 1;
    } else if (argc > 3) {
        printf("Usage: mycp SOURCE DEST\n"
                "Copying multiple files has not been implemented!\n");
        return 1;
    }
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        return 1;
    }
    int dst_fd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (dst_fd == -1) {
        perror("open");
        close(src_fd);
        return 1;
    }
    char buf[BUFFERSIZE];
    while (1) {
        int byte_read = read(src_fd, buf, BUFFERSIZE);
        if (byte_read == 0) {
            break;
        } else if (byte_read < 0) {
            perror("read");
            close(src_fd);
            close(dst_fd);
            return 1;
        }
        int byte_write = write(dst_fd, buf, byte_read);
        if (byte_write != byte_read) {
            perror("write");
            close(src_fd);
            close(dst_fd);
            return 1;
        }
    }
    close(src_fd);
    close(dst_fd);
    return 0;
}
