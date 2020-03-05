#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_BUFF 512

int main(int argc, char* argv[]){

    int src, dst;
    char buf[MAX_BUFF];
    int sizeRead, sizeWrite;

    if(argc < 3){
        perror("USAGE: filename source destination");
        exit(1);
    }

    src = open(argv[1], O_RDONLY);
    if(src == -1){
        perror("Source not openned");
        exit(2);
    }

    dst = open(argv[2], O_WRONLY | O_CREAT, 0644); // se usar O_EXCL apos O_CREAT se o ficheiro ja existir da erro
    if(dst == -1){
        perror("Destiny couldnt be openned");
        exit(3);
    }

    while((sizeRead = read(src, buf, MAX_BUFF)) >0 ){
        if((sizeWrite = write(dst, buf, sizeRead)) <= 0 || sizeRead != sizeWrite)
		perror("ERROR writing");
        close(src);
        close(dst);
        exit(4);
	}

	close(src);
	close(dst);

    return 0;
}