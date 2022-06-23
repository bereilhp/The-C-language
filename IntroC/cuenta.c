#include<stddef.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>

void * suma();
void * resta();

sem_t sem_a,sem_b,sem_c;
int cuenta = 0;

void main(){
	
	pthread_t th_a, th_b;

	sem_init(&sem_a,0,1);//MUTEX
	sem_init(&sem_c,0,0);


	pthread_create(&th_a, NULL,suma,NULL);
	pthread_create(&th_b, NULL,resta,NULL);

	pthread_join(th_a,NULL);
	pthread_join(th_b,NULL);
	
	printf("El valor de la cuenta es %d\n", cuenta);

}

void * suma(){

	for(int i = 0; i <= 10000000; i++){
		sem_wait(&sem_a);
		cuenta++;
		sem_post(&sem_a);
	}
}


void * resta(){

	for(int j = 0; j <= 10000000; j++){

		sem_wait(&sem_a);
		cuenta--;	
		sem_post(&sem_a);
	}
}

