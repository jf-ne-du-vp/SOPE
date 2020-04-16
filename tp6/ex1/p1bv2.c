#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUMITER 10000

void * thrfunc (void * arg){
    int var = * (int *) arg;

    fprintf(stderr, "Starting thread %s\n", (char*) arg);
    char tmp = var + '0';
    for(int i = 1; i < NUMITER; i++) write(STDOUT_FILENO, &tmp, 1);

    return NULL;
}

int main(){
    pthread_t ta, tb;

    int var1 = 1;
    int var2 = 2;

    pthread_create(&ta, NULL, thrfunc, &var1);
    pthread_create(&tb, NULL, thrfunc, &var2);

    //this is done so that main thread waits for thread ta and tb
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    return 0;
}