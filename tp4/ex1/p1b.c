#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo){
    printf("In SIGINT handler ...\n");
}

int main(void){
    unsigned int timeLeft;

    if(signal(SIGINT, sigint_handler) == SIG_ERR){
        fprintf(stderr, "Unable to install SIGINT handler\n");
        exit(1);
    }

    printf("Sleeping for 30 seconds... \n");
    timeLeft = sleep(30);
    printf("Time left is %d \n\n", timeLeft);
    printf("Waking up... \n");

    exit(0);
}