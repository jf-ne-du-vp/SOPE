#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])  {

 printf("Hello %s!\n", getenv("USER"));


/*name to a variable

 char* envp = getenv("USER");

 printf("Hello %s!\n", envp); 
 */

 return 0; 
 }
