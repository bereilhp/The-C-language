#include<stddef.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>

void * hello();
void * world();
sem_t sem;

void main(){
	
	pthread_t th_a, th_b;

	pthread_create(&th_a, NULL, hello,NULL);
	pthread_create(&th_b, NULL, world,NULL);
	
	pthread_join(th_a,NULL);
	pthread_join(th_b,NULL);
	
	sem_init(&sem,0, 1);
}

void * hello(){

	printf("Hello ");
	sem_post(&sem);
}

void * world(){

	sem_wait(&sem);
	printf("World!\n");
}
