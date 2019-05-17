#include<unistd.h>

int main()
{
    char buf[]="hjhlw\n";
    //参数1是一个文件描述符，参数2是输出的内容，参数3是输出内容的长度
    write(STDOUT_FILENO,buf,sizeof(buf));
    return 0;
}
