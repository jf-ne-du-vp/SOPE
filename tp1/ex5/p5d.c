#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char* argv[], char* envp[])  {


const char* user =  getenv("USER_NAME");
printf("Hello %s! \n", user);

/*
    command to add new environment variable 

    export variable=name
*/

 return 0; 
 }
