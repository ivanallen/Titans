#include <unistd.h>

int main() {
    char buf[] = "Hello world\n";
    write(STDOUT_FILENO, buf, sizeof(buf));
    return 0;
}
