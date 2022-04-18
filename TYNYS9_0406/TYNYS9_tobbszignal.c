#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handleSignals(int signum);

int main()
{
    void(*sigHandlerInterrupt)(int);
    void(*sigHandlerQuit)(int);
    void(*sigHandlerReturn)(int);
    sigHandlerInterrupt = sigHandlerQuit = handleSignals;
    sigHandlerReturn = signal(SIGINT, sigHandlerInterrupt);

    if(sigHandlerReturn == SIG_ERR)
    {
        perror("Signal error");
        return 1;
    }

    sigHandlerReturn = signal(SIGQUIT, sigHandlerQuit);

    if(sigHandlerInterrupt == SIG_ERR)
    {
        perror("Signal error");
        return 1;

    }

    for(;;)
    {
        printf("A program leallitasahoz a kovetkezoket vegezze el: \n");
        printf("1. Nyisson meg egy masik terminalt.\n");
        printf("2. Adja ki a parancsot: kill: %d \n", getpid());
        sleep(10);
    }

    return 0;
}

void handleSignals(int signum)
{
    switch(signum)
    {
        case SIGINT:
            printf("\n CTRL+C-t eszlelt\n");
            signal(SIGINT, SIG_DFL);
            break;
        case SIGQUIT:
            printf("SIQUIT aktivalodott\n");
            break;
        default:
            printf("\nFogadott jel szama: %d\n", signum);
            break;
    }

    return ;
}
