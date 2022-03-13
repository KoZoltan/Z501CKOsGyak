#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    pid_t pid01;

    if((pid01= fork())!=0){
        perror("Wrong process!");
    }
    else{
        if(execl("./child","child",(char *)NULL)<0){
            perror("execl error\n");
        }
    }
    if(waitpid(pid01, NULL, 0)<0){
        perror("wait error\n");
    }
return 0;
}
