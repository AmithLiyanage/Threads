#include<stdio.h>
#include<pthread.h>

void *entry_point1(void *value){
    int myval = (int) value;
    printf("Thread 1 : %d\n", myval);
}

void *entry_point2(void *value){
    int myval = (int) value;
    printf("Thread 2 : %d\n", myval);
}


main(){
    printf("start of main\n");

    pthread_t thread1, thread2;

    int i = 123;
    pthread_create(&thread1,NULL, entry_point1,(void*)i);


    int j = 456;
    pthread_create(&thread1,NULL, entry_point2,(void*)j);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("end of main\n");
}

