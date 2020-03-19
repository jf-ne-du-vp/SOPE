#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

bool up = true;

void usr_handler(int signo){
    if(signo == SIGUSR1){
        printf("INcresing variable \n");
        up = true;
    }
    else if(signo == SIGUSR2)
    {
        printf("Decreasing variable\n");
        up = false;
    }
}

int main(void){
    int v = 0;
    struct sigaction act;
    act.sa_handler = usr_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if(sigaction(SIGUSR1, &act, NULL) < 0){
        fprintf(stderr, "UNable to install handler");
        exit(1);
    }

    if(sigaction(SIGUSR2, &act, NULL) < 0){
        fprintf(stderr, "Unable to install handler");
        exit(1);
    }

    while(1){
        printf("Varible v = %d\n", v);
        if(up){
            v++;
        }
        else{
            v--;
        }
        sleep(1);
    }

    exit(0);
}

/*
no outro terminal usar ps -C nome para saber o seu pid
de seguida
kill -SIGUSR(1 ou 2) pid
*/