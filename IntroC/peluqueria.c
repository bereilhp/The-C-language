#include<stddef.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>

void * l1();
void * l2();
void * l3();

sem_t a,b,c, siguiente, siguiente1, inicial;

void main(){
	
	pthread_t linea1, linea2, linea3;

	sem_init(&a,0,1);
	sem_init(&b,0,1);
	sem_init(&c,0,1);
	sem_init(&inicial,0,1);
	sem_init(&siguiente,0,0);
	sem_init(&siguiente1,0,0);

	pthread_create(&linea1, NULL,l1,NULL);
	pthread_create(&linea2, NULL,l2,NULL);
	pthread_create(&linea3, NULL,l3,NULL);

	pthread_join(linea1,NULL);
	pthread_join(linea2,NULL);
	pthread_join(linea3,NULL);
	

}

void * l1(void * args){
	
	for(int i = 0; i <= 5; i++){
	sem_wait(&inicial);
	sem_wait(&a);
	sem_wait(&b);	
	printf("PIEZA 1 PRODUCIDA!!\n");
	sem_post(&a);
	sem_post(&b);
	sem_post(&siguiente);
	
	}
}


void * l2(){
	
	for(int j = 0; j <= 5; j++){
	sem_wait(&siguiente);
	sem_wait(&b);
	sem_wait(&c);	
	printf("PIEZA 2 PRODUCIDA!!\n");
	sem_post(&b);
	sem_post(&c);
	sem_post(&siguiente1);
	
	}

}
void * l3(){

	for(int h = 0; h<=5; h++){
	sem_wait(&siguiente1);
	sem_wait(&c);
	sem_wait(&a);	
	printf("PIEZA 3 PRODUCIDA!!\n");
	sem_post(&c);
	sem_post(&a);
	sem_post(&inicial);

	}


}
