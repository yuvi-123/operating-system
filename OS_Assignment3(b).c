#include<stdio.h>

main()
{
    int id;
    id=fork();

    if(id>0)
    {
        printf("Parent will sleep");
        sleep(50);
    }
    if(id==0)
        printf("I am child\n");
}
