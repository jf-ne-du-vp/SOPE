#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    struct tms t;
    clock_t start = times(&t);
    long ticks = sysconf(_SC_CLK_TCK);

    if(argc != 3){
        perror("Usage: program_name top equal \n");
        exit(1);
    }

    int top = atoi(argv[1]);
    int equal = atoi(argv[2]);
    int current = 0;
    int i = 1;

    srand(times(0));

  

    while(current != equal){
        current = rand()%top;
        printf("Iteration: %d  Current: %d  Goal: %d \n", i, current, equal);
        i++;
    }

    clock_t end = times(&t);

    printf("Tempo real: %f segundos \n", (double)(end - start)/ticks );
    printf("Tempo user CPU: %f segundos \n", (double)t.tms_utime/ticks);
    printf("Tempo system CPU: %f segundos \n", (double)t.tms_stime/ticks);


    return 0 ;
}