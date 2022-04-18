#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    if((pid = fork()) < 0)
    {
        perror("fork error");
    }
    else if(pid == 0)
    {

        if(execlp("ls", "-l", "/home/szelenyi/TYNYS9", NULL) < 0)
            perror("execl error");
    }
    if(waitpid(pid, NULL, 0) < 0)
    {
        perror("wait error");
    }

    return 0;
}
