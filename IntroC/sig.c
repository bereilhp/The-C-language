#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>

void exit1();
void exit2();

char mensaje[] = "Soy el proceso MAIN y he recibido una señal del proceso P2\n";
char mensaje1[] = "Soy el proceso P2 y he recibido una señal del proceso hijo P3\n";

void main(){
	
	printf("Soy el proceso MAIN y mi PID = %d y mi PPID = %d\n", getpid(), getppid());
	signal(SIGTERM, exit1);
		

	if(fork()==0){
		printf("Soy el proceso P1 y mi PID = %d y mi PPID = %d\n", getpid(), getppid());
	}else if(fork() == 0){
		printf("Soy el proceso P2 y mi PID = %d y mi PPID = %d\n", getpid(), getppid());
		kill(getppid(), SIGTERM);
		signal(SIGTERM, exit2);

		int pid = fork();

		if(pid == 0){
			
			printf("Soy el proceso P3 y mi PID = %d y mi PPID = %d\n", getpid(), getppid());
		}else
			kill(pid, SIGTERM);
	}

	

	while(wait(NULL)>0){};

}

void exit1(int sig){
	switch(sig){
		case(SIGTERM):
			write(1, mensaje, strlen(mensaje));
	}
}

void exit2(int sig){
	switch(sig){
		case(SIGTERM):
			write(1, mensaje1, strlen(mensaje1));
	}
}
