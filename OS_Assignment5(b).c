#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
int g = 0; 
void *myThreadFun(void *vargp) 
{ 
    int *myid = (int *)vargp; 
    int i=1;
  static int s = 0; 
  ++s; ++g,++i; 
   printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *myid, ++s, ++g,++i); 
} 
  
int main() 
{ 
    int i; 
    pthread_t tid; 
    for (i = 0; i < 5; i++) 
        pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 
   pthread_exit(NULL); 
    return 0; 
}
