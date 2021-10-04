#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SHMSZ 27
int main()
{
    char c;
    int shm_id;
    key_t key;
    char *shm, *s;

    key = 5678;

    if ((shm_id = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        return (0);
        exit(1);
    }

    if ((shm = shmat(shm_id, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        return (0);
        exit(1);
    }

    s = shm;
    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = NULL;

    while (*shm != '*')
        usleep(1);
    exit(0);
}
