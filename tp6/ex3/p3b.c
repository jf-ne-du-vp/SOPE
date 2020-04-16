#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

void * PrintHello (void *threadnum){
    printf("Hello from thread no. %d!\n", *(int *) threadnum);
    pthread_exit(NULL);
}


int main(){
    pthread_t threads[NUM_THREADS];

    int thread_num = 0;
    for(int t =0; t < NUM_THREADS; t++){
        printf("Creating thread %d\n", t);
        thread_num=t;
        pthread_create(&threads[t], NULL, PrintHello, (void*)&thread_num);
    }

    pthread_exit(0);
    //com exit(0) se ainda existirem que não tenham acabado essa sao imediatamente terminadas, se usarmos pthread_exit(0)
    //o main só termina quando os outros terminarem
}

// 3)a it shouldnt have number 10
