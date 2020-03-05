#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(int argc, char*  argv[]){


	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if( ( src = fopen(argv[1], "r")) == NULL){
		printf("Error number: %i \n", errno);
		exit(1);
	}
	if((dst = fopen (argv[2], "w")) == NULL){
		printf("Error number: %i \n", errno);
		exit(2);
	}
	while(( fgets(buf, __INT_MAX__, src)) != NULL){
		fputs(buf,dst);
	}

	fclose(src);
	fclose(dst);
	exit(0);
}
