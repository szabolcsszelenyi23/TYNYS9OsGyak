#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>
#define SHMKEY 65L
#define KEY 43L
#define PERM 00666
struct vmi {
    int  hossz;
    char szoveg[512-sizeof(int)];
} *segm;

int main()
{
	int shmid;
	key_t key;
	int size=512;
	int shmflg;

	key = SHMKEY;

	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0)
    {
	    shmflg = 00666 | IPC_CREAT;
	    if ((shmid=shmget(key, size, shmflg)) < 0)
        {
	        exit(-1);
	    }
	}

	printf("\nsmh id: %d \n", shmid);
	shmflg = 00666 | SHM_RND;
	segm = (struct vmi *)shmat(shmid, NULL, shmflg);
	if (segm == (void *)-1)
    {
		perror("Sikertelen!\n");
		exit(-1);
	}

    int id;

	if ((id = semget(KEY, 1, 0)) < 0)
    {
		if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0)
        {
			exit(-1);
		}
	}
	else
    {
		exit(0);
	}

	if (semctl(id, 0, SETVAL, 1) < 0)
    {
		perror("Hiba! A szemafo nem jött létre.\n");
	}
	struct sembuf up[1]  =  {0,  1, SEM_UNDO};
    struct sembuf down[1] = {0, -1, SEM_UNDO};

	semop(id, down, 1);
	strcpy(segm->szoveg,"Hello vilag!");
	sleep(3);
	semop(id, up, 1);
	if (semctl(id, 0, IPC_RMID, 0) < 0)
    {
		perror("Sikertelen törlés.\n");
		exit(-1);
	}

	puts("A szemafor megszünt.\n");
	shmdt(segm);
	return 0;
}
