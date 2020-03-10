#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[], char * envp[]){
    pid_t pid;

    char *comando[10] = {"ls", "-laR", argv[1], NULL};

    if(argc != 2){
        printf("usage: %s dirname\n", argv[0]);
        exit(1);
    }
    pid = fork();
    if (pid > 0){
        printf("My child is going to execuet command \"ls -laR %s\"\n", argv[1]);
        wait(NULL);    
    }
    else if(pid == 0){
        execve("/bin/ls", comando, envp);
        printf("Command not executed! \n");
        exit(1);
    }
    exit(0);
}