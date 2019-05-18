
#include <unistd.h>

int main(){
    //文件描述符： 1表示输出到屏幕上显示；
    //"iimimang\n"表示输出字符串；
    //9表示输出字符串长度
    write(1, "iimimang\n", 9);
    return 0;
}

