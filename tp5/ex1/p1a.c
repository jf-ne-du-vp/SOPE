#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(void){
    pid_t pid; 
    int first, second;
    int fd[2];

    if(pipe(fd) < 0){
        fprintf(stderr, "pipe error\n");
        exit(1);
    }

    pid = fork();

    if(pid < 0){   
        fprintf(stderr, "frok error \n");
        exit(2);
    }
    else if(pid > 0){
        close(fd[READ]);
        printf("Write numbers: \n");
        scanf("%d", &first);
        scanf("%d", &second);
        write(fd[WRITE], &first, sizeof(int));
        write(fd[WRITE], &second, sizeof(int));
        close(fd[WRITE]);
    }
    else{
        close(fd[WRITE]);
        read(fd[READ], &first, sizeof(int));
        read(fd[READ], &second, sizeof(int));

        printf("Multiplicao = %d\n", first*second);
        printf("Subtracao = %d\n", first-second);
        printf("Adicao = %d\n", first+second);

        if(second == 0){
            printf("Divisao por zero impossivel\n");
        }
        else
        {
            printf("Divisao = %d\n", first/second);
        }
        close(fd[READ]);
    }

    return 0;
}
