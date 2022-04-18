#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid, status;

    if((pid = fork()) < 0)
    {
        perror("Hiba a forkban!");
        exit(7);
    }
    else if(pid == 0)
    {
        abort();
        if(wait(&status) != pid)
        {
            perror("Hiba a wait-el!");
        }
    }
    if(WIFEXITED(status))
    {
        printf("Sikeres!");
    }

    return 0;
}
