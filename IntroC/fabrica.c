#include<stddef.h>
#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<semaphore.h>

void * cliente();
void * pelu();
int cont = 0;
sem_t max_capacidad,sofa, silla, despertarPeluquero, cortarPelo;

void main(){
	
	pthread_t th[50], peluquero;

	sem_init(&max_capacidad,0,20);
	sem_init(&sofa,0,5);
	sem_init(&silla,0,1);
	sem_init(&despertarPeluquero,0,0);
	sem_init(&cortarPelo,0,0);

	pthread_create(&peluquero, NULL,pelu,NULL);

	for(int i = 1; i<=50; i++){
		pthread_create(&th[i], NULL,cliente,(void*)&i);
		sleep(1);
	}


	for(int j = 1; j<=50; j++){
		pthread_join(th[j],NULL);
	}

	pthread_join(peluquero,NULL);
	

}

void * cliente(void * args){
	
	int car = *(int *)args;
	sem_wait(&max_capacidad);
	printf("Hola soy el cliente numero %d y acabo de entrar en la pelu\n",car);
	sem_wait(&sofa);
	printf("Hola soy el cliente numero %d y me acabo de sentar en el sofa\n",car);
	sem_wait(&silla);
	sleep(2);
	sem_post(&sofa);
	printf("Hola soy el cliente numero %d y me acabo de sentar en la silla\n",car);
	sem_post(&despertarPeluquero);
	sem_wait(&cortarPelo);
	printf("CORTANDO EL PELO DEL CLIENTE %d\n", car);
	sem_post(&silla);
	printf("EL cliente %d ya termino de cortarse el pelo. Se va\n", car);
	sem_post(&max_capacidad);



}


void * pelu(){
	
	while(cont<=50){
		sem_wait(&despertarPeluquero);
		printf("Hola soy el peluquero y te voy a cortar el pelo\n");
		sem_post(&cortarPelo);
		printf("Hola soy el peluquero y te estoy cortando el pelo\n");
		cont++;
	}
}
