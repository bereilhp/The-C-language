#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


void main(int argc, char *argv[]){
	
	int fd;
	char c;

	fd = open(argv[1], O_RDWR, 0666);

	while(read(fd,&c,1)>0){
		write(1,&c,1);
	}
}

