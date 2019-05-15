#include <unistd.h>

int main() 
{
    char buf[] ="sswhg\n";
    write(STDOUT_FILENO, buf, sizeof(buf));//读取用户的键盘输入信息
    return 0;
}
