#include <unistd.h>

int main() {
    char buf[] = "zhm\n";
    write(STDOUT_FILENO, buf, sizeof(buf));
    //参数的含义：STDOUT_FILENO为写入文件的文件描述符；buf为写入数据的缓存区；sizeof(buf)为写入数据的缓存区的大小
    return 0;
}
