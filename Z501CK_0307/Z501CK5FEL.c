#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    int pid;
    int status;

    if((pid = fork())!=0){
        perror("Hibas fork metodus");
    }
    else{
        abort();
        }
    if(wait(&status)!=pid){
            perror("Hibas wait metodus");
    }

    if(WIFEXITED(status)){
        printf("Siker ':o)'");
    }




    return 0;
}

