#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#define MSGKEY 654321L

struct msgbuf1
{
    long mtype;
    char mtext[256];

} sndbuf, *msgp;

int main()
{
    int id;
    key_t key;
    int flag;
    int rtn, size;
    int ok = 1, count = 1;

    char teszt[256];
    key = MSGKEY;
    flag = 00666 | IPC_CREAT;
    id = msgget( key, flag);
    if ( id == -1)
    {
        perror("\n Az msgget hivas nem valosult meg");
        exit(-1);
    }

    do
    {
        scanf("%s",teszt);
        msgp = &sndbuf;
        msgp->mtype = 1;
        size = strlen(msgp->mtext) + 1;
        if(strcmp("exit",teszt) != 0)
        {
            rtn = msgsnd(id,(struct msgbuf *) msgp, size, flag);
            printf("\n Az %d. msgsnd visszaadott %d-t", count, id);
            printf("\n A kikuldott uzenet: %s\n", msgp->mtext);
            count++;
        }
        else
        {
            ok = 0;
            printf("\nKilepes\n");
        }
    } while (ok == 1);

    return 0;
}
