#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUMITER 10000

void * thrfunc (void * arg){

    fprintf(stderr, "Starting thread %s\n", (char*) arg);
    for(int i = 1; i < NUMITER; i++) write(STDOUT_FILENO, arg, 1);

    return NULL;
}

int main(){
    pthread_t ta, tb;

    char var1 = 'a';
    char var2 = 'b';

    pthread_create(&ta, NULL, thrfunc, &var1);
    pthread_create(&tb, NULL, thrfunc, &var2);

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);

    return 0;
}