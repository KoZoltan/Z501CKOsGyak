#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    int status;

    if((status = system("date")<0)){
        perror("system()error");
    }

    if(WIFEXITED(status)){
        printf("Normalis befejezodes, visszaadott erteke= %d\n",WEXITSTATUS(status));
    }

    if((status = system("Z501CK")<0)){
        perror("system()error");
    }

    if(WIFEXITED(status)){
        printf("Normalis befejezodes,a visszaadott erteke= %d\n",WEXITSTATUS(status));
    }

    return 0;
