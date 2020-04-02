#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define READ 0
#define WRITE 1

int main(void){
    pid_t pid; 
    int first, second;
    int fd1[2], fd2[2];
    int result[4];

    if(pipe(fd1) < 0){
        fprintf(stderr, "pipe error\n");
        exit(1);
    }

    if(pipe(fd2) < 0){
        fprintf(stderr, "pipe error\n");
        exit(1);
    }

    pid = fork();

    if(pid < 0){   
        fprintf(stderr, "frok error \n");
        exit(2);
    }
    else if(pid > 0){
        close(fd1[READ]);
        close(fd2[WRITE]);
        printf("Write numbers: \n");
        scanf("%d", &first);
        scanf("%d", &second);
        write(fd1[WRITE], &first, sizeof(int));
        write(fd1[WRITE], &second, sizeof(int));

        sleep(5);
        read(fd2[READ], &result, sizeof(result));
        printf("Multiplicao = %d\n", result[0]);
        printf("Subtracao = %d\n", result[1]);
        printf("Adicao = %d\n", result[2]);
        printf("Divisao = %d\n", result[3]);

        close(fd2[READ]);
        close(fd1[WRITE]);
    }
    else{
        close(fd2[READ]);
        close(fd1[WRITE]);
        read(fd1[READ], &first, sizeof(int));
        read(fd1[READ], &second, sizeof(int));

        result[0] = first*second;
        result[1] = first-second;
        result[3] = first+second;
        result[4] = first/second;

        
        write(fd2[WRITE], &result, sizeof(result));
        close(fd1[READ]);
        close(fd2[WRITE]);
    }

    return 0;
}