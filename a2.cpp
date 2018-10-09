#include<stdio.h>
#include<pthread.h>

int a[100];
pthread_mutex_t mylock;

void *array_fill(void *val){
    printf("Writing \n");
    pthread_mutex_lock(&mylock);
    for(int i=0; i<100; i++){
        a[i]=i+1;
        printf("X");
    }
    pthread_mutex_unlock(&mylock);
}

void *array_read(void *value){
    printf("Reading \n");
    pthread_mutex_lock(&mylock);
    for(int i=0; i<100; i++){
        printf("%d", a[i]);
    }
    pthread_mutex_unlock(&mylock);
}


main(){
    pthread_mutex_init(&mylock, NULL);
    printf("start of main\n");
    for(int i=0; i<100; i++) a[i]=0;

    pthread_t thread1, thread2;

    pthread_create(&thread1,NULL, array_fill,NULL);

    pthread_create(&thread2,NULL, array_read,NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("end of main\n");
}


