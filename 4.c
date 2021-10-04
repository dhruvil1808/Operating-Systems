#include <stdio.h>
#include <pthread.h>
int arr[50], n, i;

void *Parent()
{
    int sum = 0;
    float average;
    printf("enter your number :=");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    average = sum / n;
    printf("The average value is:%f", average);
    pthread_exit(NULL);
}
void *Worker1()
{

    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (temp > arr[i])
        {
            temp = arr[i];
        }
    }
    printf("\nThe Minimum  value is:=%d", temp);
    pthread_exit(NULL);
}
void *Worker2()
{

    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (temp < arr[i])
        {
            temp = arr[i];
        }
    }
    printf("\nThe Maximum  value is:=%d", temp);
    pthread_exit(NULL);
}
int main()
{
    int n, i;
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    n = pthread_create(&t1, NULL, &Parent, NULL);
    pthread_join(t1, NULL);
    n = pthread_create(&t2, NULL, &Worker1, NULL);
    pthread_join(t2, NULL);
    n = pthread_create(&t3, NULL, &Worker2, NULL);
    pthread_join(t3, NULL);
}