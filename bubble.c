#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10]={4,1,3,6,5,0,7,9,8,2};
    int *p[10]={0};
    for(int i=0;i<10;i++)
    {
        p[i]=a+i;
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10-i-1;j++)
        {
            if(*p[j]<*p[j+1])
            {
                int *temp=p[j+1];
                p[j+1]=p[j];
                p[j]=temp;
            }

        }

    }


    for(int i=0;i<10;i++)
    {
        printf("%3d",*p[i]);
    }

printf("\n");

    for(int i=0;i<10;i++)
    {
        printf("%3d",a[i]);
    }

}