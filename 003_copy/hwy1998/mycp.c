#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFSIZE 2048

int main(int argc, char** argv){
	if (argc == 3){
		int srcfd = open(argv[1], O_RDONLY);
		int dstfd = open(argv[2], O_CREAT | O_WRONLY, 0666);
		if (srcfd == -1){
			perror("Open:");
			return 1;
		}
		if (dstfd == -1){
			perror("Open:");
			return 1;
		}
		int size = 0;
		char buff[BUFFSIZE] = {0};
		while ((size = read(srcfd, buff, BUFFSIZE))){
			if (write(dstfd, buff, size) != size){
				perror("Write:");
				return 1;
			}
		}
		if (size < 0){
			perror("Read:");
			return 1;
		}
		close(srcfd);
		close(dstfd);
	}else {
		printf("Usage: .//mycp src dst");
	}
}
