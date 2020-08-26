#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int pid, pid1, pid2;
    pid = fork();
    if (pid == 0)
    {
        sleep(3);
        printf("Child_1 with pid = %d From Parent with ppid = %d\n",
               getpid(), getppid());
    }

    else
    {
        pid1 = fork();
        if (pid1 == 0)
        {
            sleep(2);
            printf("Child_2 with pid = %d From Parent with ppid = %d\n",getpid(), getppid());
        }
        else {
            pid2 = fork();
            if (pid2 == 0)
            {
                printf("Child_3 with pid = %d From Parent with ppid = %d\n",getpid(), getppid());
            }
            else {
                sleep(3);
                printf("Parent with pid = %d\n", getpid());
            }
        }
    }

    return 0;
}
