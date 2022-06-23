#include<stdio.h>
#include<stdlib.h>

int suma();
int mul(int c, int d);

void main(int argc, char *argv[]){
	
	int c = atoi(argv[1]);
	int d = atoi(argv[2]);
	mul(c, d);	
}

int suma(int a, int b){

	int res;

	res = a+b;

	return printf("The answer is %d\n", res);
}

int mul(int c, int d){
	
	int result;

	result = c * d;

	return printf("The answer is %d\n", result);
}
