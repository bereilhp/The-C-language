#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


void main(int argc, char *argv[]){
	
	
	if(fork() == 0){
		execl("/bin/ls", "ls", "-l", (char*)0);
	}

	while(wait(NULL)>0);
}
