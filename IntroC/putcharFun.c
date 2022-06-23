#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>


void main(){
	
	char c = 'a';

	write(1,&c,1);
	printf("\n");
}

