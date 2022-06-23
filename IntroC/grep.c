#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


void main(int argc, char *argv[]){
	
	int fd;
	char c;
	int cont = 0;
	char var = getchar();

	fd = open(argv[1], O_RDWR, 0666);

	while(read(fd,&c,1)>0){
		if(c == var){
			cont++;
		}
	}

	printf("El char fue encontrado %d veces\n", cont);
}

