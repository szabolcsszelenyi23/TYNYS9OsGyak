#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    for(int i = 0; i < 10; i++)
    {
        printf("Szelenyi Szabolcs, TYNYS9\n");
        sleep(2);
    }

    return 0;
}
