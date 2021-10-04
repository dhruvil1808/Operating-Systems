#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSZ 27
int main()
{
    int shm_id;
    key_t key;
    char *shm, *s;
    key = 5678;
    if ((shm_id = shmget(key, SHMSZ, 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    shm = shmat(shm_id, NULL, 0);
    if (shm == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }
    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');
    for (int i = 65; i <= 90; i++)
    {
        *shm = (char)i;
        shm++;
    }
    exit(0);
}