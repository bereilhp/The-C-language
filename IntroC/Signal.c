#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>



void exit(int sig){
	
	switch(sig){	
		case(SIGINT):
			printf("Saliendo del programa al recibir la señal SIGTERM");
			exit(0);
		break;
	}

}


void main(){
		
	long i;
	long vueltas = 1000000000000;

	signal(SIGINT, exit);

	for(i = 0; i < vueltas; i++){}
		printf("Fin del programa sin recibir la señal SIGTERM\n");
		exit(EXIT_SUCCESS);	
}


