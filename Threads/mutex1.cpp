#include <iostream>
#include <pthread.h>

using namespace std;

void* funcMutex();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main(){
	int rval1, rval2;
	pthread_t thread1, thread2;
	
	if( (rval1 = pthread_create(&thread1, NULL, static_cast<void*>(funcMutex), NULL)) ){
		cout << "Error while creating thread " << rval1 << endl;
	}
		
	if( (rval2 = pthread_create(&thread2, NULL, static_cast<void*>(funcMutex), NULL)) ){
		cout << "Error while creating thread " << rval2 << endl;
	}
		
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	pthread_exit((void*)rval1);
	pthread_exit((void*)rval2);
}

void* funcMutex(){
	pthread_mutex_lock(&mutex1);
	counter++;
	cout << "Value of counter is " << counter << endl;
	pthread_mutex_unlock(&mutex1);
}
