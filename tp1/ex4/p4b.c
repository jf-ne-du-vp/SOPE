#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[])  {
 
 int i = atoi(argv[2]);
  
 while(i != 0){
  	printf("Hello %s!\n", argv[1]);  
	i--;
	} 
 
 return 0; 
 }
