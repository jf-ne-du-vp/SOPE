#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>      //to use O_WRONLY | O_CREAT

int main(int argc, char *argv[], char * envp[]){
    pid_t pid;

    //para usar execvp ou execv tenho que criar a cstring com a info 
    char *comando[10] = {"ls", "-laR", argv[1], NULL};

    if(argc > 3){
        printf("usage: %s dirname optional \n", argv[0]);
        exit(1);
    }
    pid = fork();

    if (pid > 0){
        printf("My child is going to execuet command \"ls -laR %s\"\n", argv[1]);
        wait(NULL);    
    }
    else if(pid == 0){

        if(argc == 3){
            int destiny;
            if((destiny = open(argv[2], O_WRONLY | O_CREAT, 0644)) < 0){
                printf("Error opening/creating file\n");
                exit(1);
            }
            dup2(destiny, STDOUT_FILENO);
        }   

        execv("/bin/ls", comando);
        printf("Command not executed! \n");
        exit(1);
    }
    exit(0);
}