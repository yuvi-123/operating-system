#include<stdio.h>
void sum(int a,int b,int c)
{
 int pid;
 pid=fork();
 if(pid==0)
  printf("Parents Number are %d and %d\n",a,b);
 else
    printf("Sum is Child= %d\n",c);
}
int main()
{
  int a,b,c;
  scanf("%d%d",&a,&b);
  c=a+b;
  sum(a,b,c);
  return 0;
}
