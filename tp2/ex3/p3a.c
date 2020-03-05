#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_BUFF 512

int main(int argc, char* argv[]){

    int src;
    char buf[MAX_BUFF];
    int sizeRead, sizeWrite;

    if(argc < 2){
        perror("USAGE: filename source");
        exit(1);
    }
    
    src = open(argv[1], O_RDONLY);
    if(src == -1){
        perror("Source not openned");
        exit(2);
    }


    while((sizeRead = read(src, buf, MAX_BUFF)) >0 ){
        if((sizeWrite = write(STDOUT_FILENO, buf, sizeRead)) <= 0 || sizeRead != sizeWrite)
		perror("ERROR writing");
        close(src);
        exit(4);
	}

    write(STDOUT_FILENO, "\n",1);

	close(src);

    return 0; 
}