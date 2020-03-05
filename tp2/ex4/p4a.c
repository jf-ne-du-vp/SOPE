#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF 512

int main(int argc, char* argv[]){

    char buf[MAX_BUF];
    int dst;
    int sizeRead;

    dst = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(dst == -1){
        perror("Couldnt open destiny");
        return 1;
    }

    while((sizeRead = read(STDIN_FILENO, buf, MAX_BUF)) != 0){
        write(dst, buf, sizeRead);
    }

    close(dst);

    return 0;
}