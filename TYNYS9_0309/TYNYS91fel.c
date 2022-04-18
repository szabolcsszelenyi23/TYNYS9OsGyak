#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int status;

    if((status = system("date")) < 0)  //éppen aktuális nap dátum
        perror("system() error");      //hiba esetén lefut a perror() függvény

    if(WIFEXITED(status))
        printf("Normalis befejezodes, visszaadott ertek = %d\n", WIFEXITED(status));

}
