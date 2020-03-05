//#include <stdio.h> 
#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_LENGTH_PASS 20

int main(void){

    struct termios term;
    struct termios oldterm;
    int i = 0;
    char pass[MAX_LENGTH_PASS+1], ch, echo = '*';

    write(STDIN_FILENO, "Password? ", 11);

    tcgetattr(STDIN_FILENO, &oldterm);
    term = oldterm;
    term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

    while( i < MAX_LENGTH_PASS && read(STDIN_FILENO, &ch, 1) && ch != '\n'){
        pass[i++] = ch;
        write(STDIN_FILENO, &echo, 1);
    }

    pass[i] = 0; //e necessario terminar a string

    tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
    write(STDOUT_FILENO, "\n\nPassword: ", 12);
    write(STDOUT_FILENO, pass, strlen(pass));
    write(STDOUT_FILENO, "\n", 1);

    return 0;
}