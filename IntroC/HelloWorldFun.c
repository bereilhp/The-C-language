#include<stdio.h>

int fun();

void main(){
	
	fun(10);

}

int fun(int a){
	
	return printf("Hello world %d\a\n", a);
}
