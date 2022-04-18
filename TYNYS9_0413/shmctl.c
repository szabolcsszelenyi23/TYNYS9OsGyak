#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define KEY 2022

void main()
{
    int sharedMemoryID = shmget(KEY, 0, 0);
    struct shmid_ds buffer;
    if (shmctl(sharedMemoryID, IPC_STAT, &buffer) == -1 )
    {
        perror("Nem sikerult az adatokat lekerdezni");
        exit(-1);
    }
}
