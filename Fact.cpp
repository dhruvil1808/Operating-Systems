#include <stdio.h>
#include <string.h>
#include <pthread.h>
void *func(void *arg)
{
    int factorial = 1, n;
    printf("Enter a number ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    printf("Factorial of %d is %d\n", n, factorial);
    pthread_exit(NULL);
}

int main(void)
{
    pthread_t id;
    pthread_create(&id, NULL, &func, NULL);
    pthread_join(id, NULL);
}