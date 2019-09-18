#include<unistd.h>

int main(){
    char buf[]="yida!\n";
    write(STDOUT_FILENO, buf, sizeof(buf));
    return 0;
}


