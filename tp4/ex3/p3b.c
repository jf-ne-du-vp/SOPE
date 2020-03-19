#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>
#include <sys/types.h>
#include <wait.h>

int v = 0;

void usr_handler(int signo){
    if(signo == SIGUSR1){
        printf("v = %d\n" , v++);
    }
    else if(signo == SIGUSR2)
    {
        printf("v = %d\n", v--);
    }
}

int main(void){
    int pid = fork();

    if(pid < 0){
        fprintf(stderr, "Error forking\n");
        exit(1);
    }
    else if(pid == 0){         //estamos no filho
        struct sigaction act;
        act.sa_handler = usr_handler;
        sigemptyset(&act.sa_mask);
        act.sa_flags = 0;
        printf("estou no filho\n");

        if(sigaction(SIGUSR1, &act, NULL) < 0){
            printf("Unable to install handler");
            exit(1);
        }

        if(sigaction(SIGUSR2, &act, NULL) < 0){
            printf("Unable to install handler");
            exit(1);
        }
    /*
    for(int i  = 1; i < 51; i++){
        printf("Varible v = %d\n", v);
        if(up){
            v++;
        }
        else{
            v--;
        }
    }
    */
    while(1) pause();
    }
    else if(pid > 0){        //estamos no pai
        sleep(2);
        int res;
        //bool cntn = true;;
        srand(time(0));

        for(int i = 0; i < 50; i++){
            res = rand()%2; 
            
            if(res == 0){
                kill(pid, SIGUSR1);
            }
            else if(res == 1){
                kill(pid, SIGUSR2);
            }

        //if(waitpid(pid, &status, WNOHANG) > 0 ) cntn = false;
        }
    }
    

    exit(0);
}

/*
no outro terminal usar ps -C nome para saber o seu pid
de seguida
kill -SIGUSR(1 ou 2) pid
*/

//se o pai nao esperar que o filho comece, o filho e deixado a correr e podemos enviarlhe o sinal araves do terminal