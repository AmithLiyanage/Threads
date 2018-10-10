#include<stdio.h>
#include<pthread.h>
#define SIZE 100

pthread_mutex_t mylock;
int a[SIZE];
int sum = 0; 
int wload = 50;

void *first_fifty(void *id){
    int low, high, result;
    
    low = wload * int(id);
    high = low + wload;
    
    for(int i=low; i<high; i++){
    	print("X");
    	result +=a[i];
	}
	
	pthread_mutex_lock(&mylock);
    sum+=result;
    pthread_mutex_unlock(&mylock);
}

void *next_fifty(void *id){
    printf("Reading \n");
    for(int i=0; i<100; i++) a[1]=i;
    }
    pthread_mutex_unlock(&mylock);
}


main(){
	
    pthread_mutex_init(&mylock, NULL);
    printf("start of main\n");
    for(int i=0; i<SIZE; i++) a[i]=i+1;

    pthread_t thread1, thread2;

    pthread_create(&thread1,NULL, array_fill,(void*)0);

    pthread_create(&thread2,NULL, array_read,(void*)1);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

	printf("t1 : %d t2 : %d \n");
    printf("end of main\n");
    //return 0;
}


