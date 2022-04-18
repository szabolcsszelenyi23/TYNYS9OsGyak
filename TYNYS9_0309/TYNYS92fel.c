#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    char input[100];
    printf("Adjon meg egy parancsot: ");
    scanf("%s", input);
    system(input);

    return 0;
}
