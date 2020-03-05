#include <stdio.h>
#include <stdlib.h>

void handler1(void){
    printf("Handler 1\n");
    exit(3);
}

void handler2(void){
    printf("Handler 2 \n");
    exit(3);
}

int main(void){

    
    atexit(handler1);
    atexit(handler2);


    printf("Done!\n");
    //abort(); existindo abort atexit nao e executado
    //se estiver antes de printf("Done!\n"); este tambem nao e executado

    return 0;
}

//verificar ordem de saida
