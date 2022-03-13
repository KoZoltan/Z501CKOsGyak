#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    int status;
    char beker[50];

    printf("Adjon meg egy unix parancsot: ");
    scanf("%s",&beker);
    if((status = system(beker))<0){
        perror("system()error");
    }
    if(WIFEXITED(status))
        printf("A program helyesen futott le, visszateresi erteke: %d\n", WEXITSTATUS(status));

    return 0;
}
