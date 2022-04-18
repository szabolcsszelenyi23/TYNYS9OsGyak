#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define KEY 2022

int main()
{
    int sharedMemoryID = shmget(KEY, 256, IPC_CREAT | 0666);

    return 0;
}
