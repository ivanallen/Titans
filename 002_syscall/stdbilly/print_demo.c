#include <unistd.h>

int main() {
    char buf[] = "stdbilly\n";
    /*ssize_t write(int fd, const void *buf, size_t count)
     fd:文件描述符,STDOUT_FILENO表示向屏幕输出
     buf:是指向一段内存单元的指针
     count:要写入的最大字节数
     返回值:如果写入成功,返回写入的字节数,否则返回-1
     */
    write(STDOUT_FILENO, buf, sizeof(buf));
    return 0;
}
