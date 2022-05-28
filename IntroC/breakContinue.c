#include<stdio.h>

int x = 100;

void main(){

	while(x<=100){
		
		x--;

		if(x <= 0){
			
			printf("Negative Value of X\n");
			printf("%d\n", x);
			break;

		}

		if(x == 50){
			
 			printf("gone 50%%\n");
			printf("%d\n",x);
			continue;
		}
	}

}
