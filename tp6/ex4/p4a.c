#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define N 100

void * thrfnc(void *mynum){
    sleep(1);
    printf("I am thread %ld and the parameter passed to me is %d.\n", pthread_self(), *(int*) mynum);
    pthread_exit(NULL);
}


int main(){
    pthread_t threads[N];
    int thrarg[N];

    for(int i = 1; i <= N; i++){
        thrarg[i] = i;
        pthread_create(&threads[i], NULL, thrfnc, (void*)&thrarg[i]);
        //pthread_join(threads[i], NULL);
    }

    
    for(int t = 1; t <= N; t++){
        pthread_join(threads[t], NULL);
    }
    


    pthread_exit(0);
    //exit(0);
    //return 0; 
}