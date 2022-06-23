#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

char name[] = "archivo.txt";
char mensaje[] = "Hola Mundo!\n";
char c;

void main(){

	int fd;
	fd = open(name, O_CREAT | O_RDWR, 0666);
	//printf("Soy fd y mi valor es = %d\n", fd);
	
	write(1,mensaje, strlen(mensaje));

	lseek(fd,0,SEEK_SET);

	while(read(fd,&c,1)>0){
		
		sleep(1);		
		printf("%c", c);
		fflush(stdout);
	}
}

