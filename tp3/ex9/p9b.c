#include <sys/types.h>
#include <unistd.h>     //frok
#include <wait.h>       //wait
#include <stdlib.h>     //exit
#include <stdio.h>      //printf


int main(int argc, char *argv[], char *envp[]){
    int status;
    pid_t pid;
    char *comando[10] = {"ls", "-laR", argv[1], NULL};

    pid = fork();

    if(pid > 0){
        waitpid(pid, &status, 0);
        printf("Son terminated with code: %d \n", WEXITSTATUS(status));
        printf("Child terminated normal? %d\n", WIFEXITED(status));
        printf("child terminated with error? %d\n", WIFSIGNALED(status));    
    }
    if(pid == 0){
        execv("/bin/ls", comando);
        printf("Error executing exec\n");
        exit(1);
    }
    exit(0);
}