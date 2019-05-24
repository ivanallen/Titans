#include <unistd.h>   //导入linux系统调用

int main() {
    char buf[] = "shyshy903!\n";  
    /*是文件描述符,参数二是需要输出的，参数三为输出字符数*/
    write(STDOUT_FILENO, buf, sizeof(buf));
    
    return 0;
}
