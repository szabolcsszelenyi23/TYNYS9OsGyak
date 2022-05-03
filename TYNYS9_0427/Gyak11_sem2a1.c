#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define KEY 77777L

union semun {
    int val;                 /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array;   /* Array for GETALL, SETALL */
    struct seminfo *__buf;   /* Buffer for IPC_INFO (Linux-specific) */
};

void main() {
    union semun arg;

    int semID = semget(KEY, 0, 0);
    if (errno == ENOENT)
    {
        semID = semget(KEY, 1, IPC_CREAT | 0666);
        printf("Szam: ");
        scanf("%d" ,&(arg.val));
    }
    else
    {
        arg.val = 1;
    }

    semctl(semID, 0, SETVAL, arg);

    printf("A szemafor erteke (1) : %d\n", semctl(semID, 0, GETVAL));

}
