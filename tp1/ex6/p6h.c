#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(int argc, char*  argv[]){

	char* infile;
	char* outfile;

	if(argc >= 3){
		infile = argv[1];
		outfile = argv[2];
	}
	else{
		printf("Usage: nome_do_executavel file1 file2 \n");
	}
	
	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if( ( src = fopen(infile, "r")) == NULL){
		printf("Error number: %i \n", errno);
		exit(1);
	}
	if((dst = fopen (outfile, "w")) == NULL){
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
