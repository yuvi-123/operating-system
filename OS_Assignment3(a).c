#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int pid = fork();

    if (pid > 0)
        printf("In a Parent process.....");
    else if (pid == 0)
    {
        sleep(30);
        printf("In a Child process.....");
    }

    return 0;
}
