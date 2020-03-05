#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFF 256

int main(int argc, char* argv[]){

    FILE* src,* dst;
    char buf[MAX_BUFF];

    if(argc < 3){
        perror("USAGE: filename source destination");
        exit(1);
    }

    if((src = fopen(argv[1], "r")) == NULL){
        perror("Source not openned");
        exit(2);
    }

    if((dst = fopen(argv[2], "w")) == NULL){
        perror("Destine couldnt be openned");
        exit(3);
    }

    while(( fgets(buf, __INT_MAX__, src)) != NULL){
		fputs(buf,dst);
	}

	fclose(src);
	fclose(dst);

    return 0;
}