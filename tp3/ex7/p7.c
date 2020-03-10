#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char prog[20];

    sprintf(prog, "%s.c", argv[1]);  //first argument is stored string prog
    execlp("gcc", "gcc", prog, "-Wall", "-o", argv[1], NULL);
    printf("Error changing code");
    exit(-1);
}

//printf only done if error