#include <unistd.h>
int main(){
    write(1,"bluewindroad\n",13);
/*
the 1 means we are going to send the string to the screan.
"bluewindroad\n"is the string we want to send, here we give the computer its address.
the 13 is the length of string we want to send.
*/
    return 0;
}
