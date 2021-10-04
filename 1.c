#include <stdio.h>
#include <string.h>
#include <pthread.h>

int i = 2;

void *func(void *arg)
{
    printf("Inside the thread\n");
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t id;

    int j = 1;
    pthread_create(&id, NULL, &func, NULL);
    printf("Thread Created\n");
    pthread_join(id, NULL);
    printf("Thread Ends\n");
    pthread_exit(NULL);
}