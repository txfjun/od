
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void show (int* a,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");

}

int * genarr(int len)
{
    int *a=(int*)calloc(len,sizeof(int));
    time_t t;
    time(&t);
    srand(t);
    for(int i=0;i<len;i++)
    {
      
       a[i]= rand()%400;
    }
    
    return a;
}

