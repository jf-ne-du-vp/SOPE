#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 256

int main(void){

    char buf[MAX_BUFFER];
    printf("Linha de comandos: ");
    fgets(buf, MAX_BUFFER, stdin);

    char* token = strtok(buf, " ");

    while(token != NULL){
        printf("%s \n", token);
        token = strtok(NULL, " ");
    }

// Splits str[] according to given delimiters.
// and returns next token. It needs to be called
// in a loop to get all tokens. It returns NULL
// when there are no more tokens.
//char * strtok(char str[], const char *delims);


    return 0;
}