#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


void main(){
	
	if(fork() == 0){
		printf("Soy el proceso hijo y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else if(fork()==0){
		printf("Soy el proceso hijo1 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else if(fork()==0){
		printf("Soy el proceso hijo2 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else if(fork()==0){
		printf("Soy el proceso hijo3 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else if(fork()==0){
		printf("Soy el proceso hijo4 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else if(fork()==0){
		printf("Soy el proceso hijo5 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else if(fork()==0){
		printf("Soy el proceso hijo6 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else if(fork()==0){
		printf("Soy el proceso hijo7 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else if(fork()==0){
		printf("Soy el proceso hijo8 y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else
		printf("Soy el proceso padre y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	while(wait(NULL)>0);


}
