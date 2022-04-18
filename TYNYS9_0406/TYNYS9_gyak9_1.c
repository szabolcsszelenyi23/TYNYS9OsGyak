#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

void handleSigalarm();

int main()
{
    printf("A program pidje: %d\n",getpid());
    signal(SIGALRM, handleSigalarm);
    pause();
    printf("Kibillent\n");
    exit(0);
    return 0;
}

void handleSigalarm()
{
    printf("TYNYS9\n");
}
