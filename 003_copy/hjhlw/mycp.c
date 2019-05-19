#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("your parameters are incorrect\n");
        return -1;
    }

    int src=open(argv[1],O_RDONLY);
    if(src==-1)
    {
        printf("Error : reading the file\n");
        perror("Error ");
        return -1;
    }
    int dst=open(argv[2],O_WRONLY|O_CREAT,0666);
    if(dst==-1)
    {
        printf("Error : creating the file\n");
        perror("Error ");
        return -1;

    }

    char buf[1024]="";
    int count=0;
    while(1)
    {
        count=(dst,buf,sizeof(buf));
        if(read==-1||read==0)
            break;
        write(dst,buf,strlen(buf));
    }
    return 0;
}
