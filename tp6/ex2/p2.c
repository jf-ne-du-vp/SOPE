#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define STDERR 2

int N = 50000;

void * thrfunc(void * arg){
    int times_printed = 0;
    int var = * (int *) arg;
    fprintf(stderr, "Starting thread %s\n", (char*) arg);
    char tmp = var + '0';

    while(N > 0){
        times_printed++;
        N--;
        write(STDERR, &tmp, 1);
    }

    void * ret = malloc(sizeof(int));
    *(int*) ret = times_printed;
    return ret;
}

int main(){
    pthread_t ta, tb;

    int var1 = 1;
    int var2 = 2;

    void *ret1, * ret2;
    
    pthread_create(&ta, NULL, thrfunc, &var1);
    pthread_create(&tb, NULL, thrfunc, &var2);

    pthread_join(ta, &ret1);
    pthread_join(tb, &ret2);

    printf("\nThread com o valor 1 escreveu %d vezes. \n", *(int*) ret1);
    printf("Thread com o valor 2 escreveu %d vezes. \n", *(int *) ret2);
    printf("Foram impressos um total de %d caracteres. \n", *(int*) ret1 + *(int *) ret2);
    //por vezes sao impressas mais que N vezes, sera visto mais a frente como resolver

    return 0;
}