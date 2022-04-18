#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void kezelo(int i)
{
    printf("Signal kezelese: %d\n",i);
    return;
}

int main()
{
    printf("PID: %d\n",getpid());
    printf("Signal kezelo atvetele: %d\n",signal(SIGTERM,&kezelo));
    while(1)
    {
        printf("lepes\n");
        sleep(3);
    }

    return 0;
}
