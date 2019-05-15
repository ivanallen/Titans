#include <unistd.h>
int main(){
	const char name[]="shy903\n";
	
	write(STDOUT_FILENO,name,sizeof(name));
/* 
arg1 is used to represent a file accession;
arg2 is a string constant ;
arg3 is a function to read the string;
*/

	return 0;//if correct return 0,else return -1;
}
