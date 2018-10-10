#include<stdio.h>
#include<pthread.h>
#define SIZE 100

int a[SIZE];
pthread_mutex_t mylock;

void *array_fill(void *val){
	
	pthread_mutex_lock(&mylock);
	printf("\nWritting\n");
	
	for(int i=0; i<100; i++){
		a[i] = i+1;
		printf("X");
	}
	pthread_mutex_unlock(&mylock);
}

void *array_read(void *val){
	
	pthread_mutex_lock(&mylock);
	printf("\nReading\n");
	for(int i=0; i<100; i++){
		printf("%d", a[i]);
	}
	pthread_mutex_unlock(&mylock);
}

main(){
	pthread_mutex_init(&mylock, NULL);
	printf("Start of main\n");
	for(int i=0; i<SIZE; i++) a[i]=0;
	
	pthread_t thread1, thread2;
	int thr1, thr2;	
	
	thr1 = pthread_create(&thread1, NULL, array_fill, NULL);
	
	thr2 = pthread_create(&thread2, NULL, array_read, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	
	printf("\n Thread 1 : %d", thr1);
	printf("\n Thread 2 : %d", thr2);
	
	printf("\nEnd of main\n");
}
