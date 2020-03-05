#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){
    pid_t pid;
    //int status;

    write(STDOUT_FILENO, "Antes do fork\n", 14); //o \n conta como um
    //printf("Antes do fork.\n");   //aqui se nao tivesse 0 \n aparecia nos 2

    pid = fork();

    if(pid < 0){
        perror("fork error: ");
        return -1;
    }
    else if(pid == 0){
        write(STDOUT_FILENO, " world!\n", 8);
    }
    else if(pid > 0){
        //waitpid(pid, &status, 0);
        write(STDOUT_FILENO, "Hello", 5);
    }
    

    return 0;
}

//mesmo que else if(pid == 0) (btw 0 indica que é o filho) estivesse em primeiro o resultado seria o errado