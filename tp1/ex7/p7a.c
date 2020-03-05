#include <stdio.h>
#include <stdlib.h>

void handler1(void){
    printf("Handler 1\n");
}

void handler2(void){
    printf("Handler 2 \n");
}

int main(void){

    
    atexit(handler1);
    atexit(handler2);

    
    printf("Done!\n");

    return 0;
}

//verificar ordem de saida
