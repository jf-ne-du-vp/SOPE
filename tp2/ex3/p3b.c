#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_BUFF 512

int main(int argc, char* argv[]){

    int src, dst;
    char buf[MAX_BUFF];
    int sizeRead, sizeWrite;

    if(argc < 2){
        perror("USAGE: filename source OR filename source write");
        exit(1);
    }

    src = open(argv[1], O_RDONLY);
    if(src == -1){
        perror("Source not openned");
        exit(2);
    }

    if(argc == 2){
    while((sizeRead = read(src, buf, MAX_BUFF)) >0 ){
        if((sizeWrite = write(STDOUT_FILENO, buf, sizeRead)) <= 0 || sizeRead != sizeWrite)
		perror("ERROR writing");
        close(src);
        exit(4);
	}
    }

    else if (argc > 2)
    {
        dst = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644);
        dup2(dst, STDOUT_FILENO);       //needs to be openned
        while((sizeRead = read(src, buf, MAX_BUFF)) >0 ){
        if((sizeWrite = write(STDOUT_FILENO, buf, sizeRead)) <= 0 || sizeRead != sizeWrite)
		perror("ERROR writing");
        close(src);
        close(dst);
        exit(4);
	}
    close(dst);
    }

    close(src);
    

    return 0;
}