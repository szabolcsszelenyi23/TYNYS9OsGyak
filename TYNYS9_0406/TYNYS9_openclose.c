#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define FILE "TYNYS9.txt"

int main()
{
    int fileHandle = open(FILE, O_RDWR);
    if(fileHandle == -1)
    {
        perror("Nem sikerult megnyitni a fajlt!");
        return 1;
    }
    else
    {
        printf("Sikeres volt a fajl megnyitasa!\n");
    }
    char tartalom[120];

    int olvasott = read(fileHandle, tartalom, sizeof(tartalom));
    printf("Beolvasott tartalom: \"%s\" osszesen: \"%i\" byte.\n",tartalom,olvasott);

    lseek(fileHandle, 0, SEEK_SET);

    char text[] = "teszt";
    int irt = write(fileHandle, text, sizeof(text));
    printf("A fajlba irtuk a(z) \"%s\" szoveget. Osszesen: \"%i\" byte. \n", text, irt);

    close(fileHandle);

    return 0;
}
