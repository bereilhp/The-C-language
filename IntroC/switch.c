#include<stdio.h>

void main(){

	char c;

	switch(c = getchar()){
		
		case 'r':
		case 'R':
		printf("Red\n");
	break;
		case 'y':
		case 'Y':
		printf("Yellow\n");
	break;
		case 'b':
		case 'B':
		printf("Black\n");
	break;

		default: 
		printf("Wrong Char\n");

	}
}
