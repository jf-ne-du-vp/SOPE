#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(void){
	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if( ( src = fopen("infile.txt", "r")) == NULL){
		perror("Error opening file to read\n");
		exit(1);
	}
	if((dst = fopen ("outfile.txt", "w")) == NULL){
		perror("Error opening file to write\n");
		exit(2);
	}
	while(( fgets(buf, __INT_MAX__, src)) != NULL){
		fputs(buf,dst);
	}

	fclose(src);
	fclose(dst);
	exit(0);
}
