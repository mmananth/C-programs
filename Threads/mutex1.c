#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* funcMutex();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main(){
	int rval1, rval2;
	pthread_t thread1, thread2;
	
	if( (rval1 = pthread_create(&thread1, NULL, funcMutex, NULL)) ){
		printf("Error while creating thread %d\n", rval1);
	}
		
	if( (rval2 = pthread_create(&thread2, NULL, funcMutex, NULL)) ){
		printf("Error while creating thread %d\n", rval2);
	}
		
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	exit(0);
}

void* funcMutex(){
	pthread_mutex_lock(&mutex1);
	counter++;
	printf("Value of counter is %d\n", counter);
	pthread_mutex_unlock(&mutex1);
}