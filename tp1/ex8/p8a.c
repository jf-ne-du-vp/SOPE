#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]){

    if(argc != 3){
        perror("Usage: program_name top equal \n");
        exit(1);
    }

    int top = atoi(argv[1]);
    int equal = atoi(argv[2]);
    int current = 0;
    int i = 1;

    srand(time(0));

    while(current != equal){
        current = rand()%top;
        printf("Iteration: %d  Current: %d  Goal: %d \n", i, current, equal);
        i++;
    }

    return 0 ;
}