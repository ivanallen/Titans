#include <unistd.h>
int main() {
    char buf[] = "Hello, fuxiangjie!\n";
    write(STDOUT_FILENO, buf, sizeof(buf));
    // arg1: file descriptor
    // arg2: a pointer, point to a buf that stores what we're going to write.
    // arg3: the number of bytes we're going to write.  
    // return value: on success, the number of bytes written is returned. On error, return -1.
    return 0;
}
