#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int pid, pid_terminated, status;
    char cmd[100];

    printf("Command (or quit)? ");
    scanf("%s", cmd);

    while(strcmp(cmd,"quit") != 0){
        pid = fork();

        if(pid > 0){
        pid_terminated = wait(&status);
        printf("Parent: son %d terminated with exit code %d \n", pid_terminated, WEXITSTATUS(status));
        }
        else{
            execlp(cmd,cmd, NULL);
            printf("Command not found!!! \n");
            exit(1);
        }

        printf("Command (or quit)?");
        scanf("%s", cmd);   
    }
    

    return 0;
}