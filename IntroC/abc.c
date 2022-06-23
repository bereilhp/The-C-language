#include<stddef.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>

void * a();
void * b();
void * c();

sem_t sem_a,sem_b,sem_c;

void main(){
	
	pthread_t th_a, th_b, th_c;

	sem_init(&sem_a,0, 1);
	sem_init(&sem_b, 0, 0);
	sem_init(&sem_c,0,0);


	pthread_create(&th_a, NULL,a,NULL);
	pthread_create(&th_b, NULL,b,NULL);
	pthread_create(&th_c, NULL,c,NULL);

	pthread_join(th_a,NULL);
	pthread_join(th_b,NULL);
	pthread_join(th_c,NULL);
	
	printf("\n");

}

void * a(){

	for(int i = 0; i <= 2; i++){
		sem_wait(&sem_a);
		printf("A");
		sem_post(&sem_b);
	}
}


void * b(){

	for(int j = 0; j <= 2; j++){
		sem_wait(&sem_b);
		printf("B");
		sem_post(&sem_c);
	}
}

void * c(){

	for(int k = 0; k <= 2; k++){
		sem_wait(&sem_c);
		printf("C");
		sem_post(&sem_a);
	}
}


