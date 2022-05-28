#include<stdio.h>

void Hello();

void main(){

	Hello("Hello World");
}

void Hello(char mensaje[20]){

	printf("%s\n", mensaje);
}
