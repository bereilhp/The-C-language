#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


void main(int argc, char *argv[]){
	
	int fd, des;
	char c;

	fd = open(argv[1], O_RDWR, 0666);
	des = open(argv[2], O_CREAT | O_RDWR, 0666);

	while(read(fd,&c,1)>0){
		write(des,&c,1);
	}
}

