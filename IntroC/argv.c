#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc, char *argv[]){

	if(argc < 2){
		printf("Too many arguments please only add one, the password\n");
	}else{
		
		if (!strcmp(argv[1], "pass")){
			printf("You are in\n");
		}else
			printf("Wrong password\n");
	
	}
}
