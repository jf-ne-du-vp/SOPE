#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

struct numbers{
    int first;
    int second;
};

int main(void){
    pid_t pid;
    int fd[2];
    struct numbers num;

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
        /*
        scanf("%d", &num.first);
        scanf("%d", &num.second);
        */
        fscanf(stdin, "%d %d", &num.first, &num.second);
        write(fd[WRITE], &num, sizeof(num));
        close(fd[WRITE]);
    }
    else{
        close(fd[WRITE]);
        read(fd[READ], &num, sizeof(num));

        printf("Multiplicao = %d\n", num.first*num.second);
        printf("Subtracao = %d\n", num.first-num.second);
        printf("Adicao = %d\n", num.first+num.second);

        if(num.second == 0){
            printf("Divisao por zero impossivel\n");
        }
        else
        {
            printf("Divisao = %d\n", num.first/num.second);
        }
        close(fd[READ]);
    }

    return 0;
}
