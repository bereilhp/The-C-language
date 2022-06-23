#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<signal.h>


void * process();

void main(){
	
	pthread_t th_a,th_b, th_c, th_d, th_e, th_f, th_g, th_h;

	pthread_create(&th_a,NULL, process, "THREAD A\n");
	pthread_create(&th_b,NULL, process, "THREAD B\n");
	pthread_create(&th_c,NULL, process, "THREAD C\n");
	pthread_create(&th_d,NULL, process, "THREAD D\n");
	pthread_create(&th_e,NULL, process, "THREAD E\n");
	pthread_create(&th_f,NULL, process, "THREAD F\n");
	pthread_create(&th_g,NULL, process, "THREAD G\n");
	pthread_create(&th_h,NULL, process, "THREAD H\n");
	

	pthread_join(th_a,NULL);
	pthread_join(th_b,NULL);
	pthread_join(th_c,NULL);
	pthread_join(th_d,NULL);
	pthread_join(th_e,NULL);
	pthread_join(th_f,NULL);
	pthread_join(th_g,NULL);
	pthread_join(th_h,NULL);
}

void * process (void * args){

		printf("%s",(char *)args);
		fflush(stdout);
		pthread_exit(0);

}


