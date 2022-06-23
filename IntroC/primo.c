#include<stdio.h>
#include<stdlib.h>


void main(int argc, char *argv[]){

	int numero = atoi(argv[1]);
	int contador = 0;

	for(int i = 1; i <= numero; i++){
		
		if(numero % i == 0 ){
		
		contador++;
		
		}
	}

	if(contador == 2){
		printf("ES PRIMO\n");
	}else
		printf("NO ES PRIMO\n");

}
