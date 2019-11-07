#include <stdio.h>
#include <stdlib.h>

extern int *genarr(int len);
extern void show(int *a,int len);

void insert(int *a,int start,int end)
{
    int i,j;
    int temp;
    for(i=start+1;i<end;i++)
    {
        for(j=i;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }
}




int main()
{


    int *a=genarr(100);
    insert(a,0,100);
    show(a,100);
    return 0;
}