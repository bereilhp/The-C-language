#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void main(){

	int var = 0;


//	printf("Soy el proceso MAIN y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	
	if(fork() == 0){
		printf("Soy el proceso P1 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
		var++;
		printf("%d\n", var);

	}else if(fork()==0){
		printf("Soy el proceso P2 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
		var++;
		printf("%d\n", var);

	}else if(fork()==0){
		printf("Soy el proceso P3 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
		var++;
		printf("%d\n", var);

		if(fork()== 0){
			printf("Soy el proceso P5 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
		}
	}else if(fork()==0){
		printf("Soy el proceso P4 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());

		if(fork()==0){
			
			printf("Soy el proceso P6 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
		}
	}else
		
		printf("Soy el proceso MAIN y mi PID es %d y mi PPID es %d\n", getpid(), getppid());

	while(wait(NULL)>0);


}
