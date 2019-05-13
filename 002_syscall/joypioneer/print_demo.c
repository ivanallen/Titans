#include <unistd.h>

int main() {
    const char buf[] = "Hello, joypioneer!\n";
    /*
    ssize_t write(int fd, const void *buf, size_t count);
    arg1: file descriptor;
    arg2: a pointer to memory buffer;
    arg3: the number of bytes to write.  
    return value: on success, the number of bytes written is returned. On error, return -1.
    */
    
    write(STDOUT_FILENO, buf, sizeof(buf));
    
    return 0;
}
