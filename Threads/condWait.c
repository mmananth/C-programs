#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define COUNT_DONE	10
#define COND_WAIT1	3
#define COND_WAIT2	6

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t 	condition_var = PTHREAD_COND_INITIALIZER;

void* funcCount1();
void* funcCount2();
int count = 0;

int main(){
	pthread_t thread1, thread2;
	
	pthread_create(&thread1, NULL, &funcCount1, NULL);
	pthread_create(&thread2, NULL, &funcCount2, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("Final count %d\n", count);
	
	exit(0);
}

void* funcCount1(){
	for(;;){
		pthread_mutex_lock(&count_mutex);
		
		pthread_cond_wait(&condition_var, &count_mutex);
		count++;
		printf("counter value function 1 %d\n", count);	
		pthread_mutex_unlock(&count_mutex);
		
		if(count >= COUNT_DONE)	return(NULL);
	}
}

void* funcCount2(){
	for(;;){
		pthread_mutex_lock(&count_mutex);	
		if(count < COND_WAIT1 || count > COND_WAIT2){
			pthread_cond_signal(&condition_var);
		}
		else{
			count++;
			printf("counter value function 2 %d\n", count);
		}
		pthread_mutex_unlock(&count_mutex);	
		
		if(count >= COUNT_DONE) return(NULL);
	}
}

