#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
    pid_t pid;
    int status;

    pid = fork();

    switch(pid){
        case -1: 
            perror("fork error: ");
            break;
        case 0:
            pid = fork();
            if(pid == 0){
                write(STDOUT_FILENO, "Hello", 5);
            }
            else if(pid > 0){
                waitpid(pid, &status, 0);
                write(STDOUT_FILENO, " my", 3);
            }
            break;
        default:
            waitpid(pid, &status, 0);
            write(STDOUT_FILENO, " friends!\n", 10);
            break;
    }

    return 0;
}