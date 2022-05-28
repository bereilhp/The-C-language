#include<stdio.h>

void main(){
	
	char name[20];
	int age;
	float weight;
	scanf("%s %d %f", name, &age, &weight);

	printf("Hello my name is %s. I am %d years old and my weight is %f\n", name, age, weight);
}
