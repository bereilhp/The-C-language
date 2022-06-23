#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


void main(){
	
	pid_t pid;
	pid=fork();
	
	if(pid == 0){
		printf("Soy el proceso hijo y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
	}else
		printf("Soy el proceso padre y mi PID es %d y mi PPID es %d\n", getpid(), getppid());
}

