#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHMKEY 65L
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

	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("A rendszerhívás sikertelen!\n");
	    exit(-1);
	}

	shmflg = 00666 | SHM_RND;
	segm = (struct vmi *)shmat(shmid, NULL, shmflg);
	if (segm == (void *)-1) {
		perror("Sikertelen kapcsolódás!\n");
		exit(-1);
	}

	if (strlen(segm->szoveg) > 0)
    {
		printf("A szoveg: %s\n",segm->szoveg);
    }
	int rtn = shmctl(shmid, IPC_RMID, NULL);
	printf("Szegmens torolve. Hibakod: %d\n", rtn);
	return 0;
}
