#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


void main(){

	int fd,fd2;
	fd = open("prueba1.txt", O_CREAT | O_RDWR, 0666);
	printf("Soy fd y mi valor es = %d\n", fd);
	
	close(fd);

	fd2 = open("prueba2.txt", O_CREAT | O_RDWR, 0666);
	printf("Soy fd y mi valor es = %d\n", fd2);

	}

