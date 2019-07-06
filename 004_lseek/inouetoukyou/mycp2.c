#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
const int BUFFERSIZE = 4096;
int arg_judge(int argc) {
    if (argc < 3) {
        printf("Usage: mycp2 SOURCE DEST\n"
               "Copy SOURCE to DEST, only for files.\n");
        return 1;
    } else if (argc > 3) {
        printf("Usage: mycp2 SOURCE DEST\n"
                "Copying multiple files has not been implemented!\n");
        return 1;
    }
    return 0;
}

int copy_2nd_half_judge(int src_fd, int dst_fd) {
    int src_file_len = lseek(src_fd, 0, SEEK_END);
    if (src_file_len < 0) {
        perror("lseek");
        return src_file_len;
    }
    int mid_pos = lseek(src_fd, src_file_len / 2, SEEK_SET);
    if (mid_pos < 0) {
        perror("lseek");
        return mid_pos;
    }
    return 0;
}

int copy_2nd_half(int src_fd, int dst_fd) {
    int status_copy_judge = copy_2nd_half_judge(src_fd, dst_fd);
    if (status_copy_judge != 0) {
        return status_copy_judge;
    }
    char buf[BUFFERSIZE];
    while (1) {
        int byte_read = read(src_fd, buf, BUFFERSIZE);
        if (byte_read == 0) {
            break;
        } else if (byte_read < 0) {
            perror("read");
            return 1;
        }
        int byte_write = write(dst_fd, buf, byte_read);
        if (byte_write != byte_read) {
            perror("write");
            return 1;
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    int status_arg_judge = arg_judge(argc);
    if (status_arg_judge != 0) {
        return status_arg_judge;
    }

    //try_open
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("open");
        return src_fd;
    }
    int dst_fd = open(argv[2], O_CREAT | O_WRONLY, 0666);
    if (dst_fd < 0) {
        perror("open");
        close(src_fd);
        return dst_fd;
    }

    int status_copy_2nd_half = copy_2nd_half(src_fd, dst_fd);
    close(src_fd);
    close(dst_fd);
    return status_copy_2nd_half;
}
