#include <pthread.h>
#include <stdio.h>
int n = 0;
long fib[500];
void *runner(void *param)
{
    if (n <= 0)
    pthread_exit(0);
    fib[0] = 0;
    if (n > 1) 
    {
        fib[1] = 1;
        for (int i = 2; i<n; i++)
        fib[i] = fib[i-1] + fib[i-2];
    }
    pthread_exit(0);
    }
int main(int argc, char *argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    printf("Print numbers to be in fibonacii series: ");
    scanf("%d", &n);
    if (n > 500)
    {
        printf("Printing as many as possible: 500\n");
        n= 500;
    }
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);
    if (n > 0)
    printf("%ld", fib[0]);
    for (int i = 1; i < n; i++)
    printf(",%ld", fib[i]);
    printf("\n");
    return 0;
}
