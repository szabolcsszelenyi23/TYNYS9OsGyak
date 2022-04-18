#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>
#define KEY 777777

void main()
{
    pid_t process1;
    pid_t process2;
    pid_t process3;

    process1 = fork();
    if (process1 == 0)
    {
        int sharedMemoryID = shmget(KEY, 256, IPC_CREAT | 0666);
        if (sharedMemoryID == -1)
        {
            perror("Nem sikerult lefoglalni a memoriar\n");
            exit(-1);
        }
        printf("Process1 lefoglalta a memoriat!\n");
    }
    else
    {
         process2 = fork();
         if (process2 == 0)
         {
            printf("Process 2 olvas\n");
            int sharedMemoryID = shmget(KEY, 0, 0);
            char *s = shmat(sharedMemoryID, NULL, SHM_RND);
            strlen(s) > 0 ? printf("osztott memoriaban szereplo szoveg : %s\n", s)
                          : printf("Nincs benne szoveg\n");
            strcpy(s, "Ez egy uj szoveg");
            printf("process2 kuldte az uzenetet.\n");
         }
         else
         {
             process3 = fork();
             if (process3 == 0)
             {
                printf("process3: \n");
                int sharedMemoryID = shmget(KEY, 0, 0);
                struct shmid_ds buffer;
                if (shmctl(sharedMemoryID, IPC_STAT, &buffer) == -1)
                {
                    perror("Nem sikerult lekerdezni.\n");
                    exit(-1);
                }
                printf("Szegmens merete: %ld\n", buffer.shm_segsz);
                printf("utolso operaciot kiado processz pidje : %d\n", buffer.shm_lpid);
             }
         }
    }
}
