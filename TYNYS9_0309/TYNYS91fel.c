#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int status;

    if((status = system("date")) < 0)  //�ppen aktu�lis nap d�tum
        perror("system() error");      //hiba eset�n lefut a perror() f�ggv�ny

    if(WIFEXITED(status))
        printf("Normalis befejezodes, visszaadott ertek = %d\n", WIFEXITED(status));

}
