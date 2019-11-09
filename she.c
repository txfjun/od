#include<stdio.h>
#include<stdlib.h>
#define N 10

int main()
{
    int a[N][N]={0};
    int data = 1;
    for(int i=0,j=0,k=0;k<(N+1)/2;k++)
    {
        while(j<N-k)
        {
            a[i][j]=data;
            data++;
            j++;

        }
        j--;
        i++;
        while(i<N-k)
        {
            a[i][j]=data;
            data++;
            i++;
        }
        i--;
        j--;
        while (j>=k)
        {
            a[i][j]=data;
            data++;
            j--;
        }
        j++;
        i--;
        while (i>k+1)
        {
            a[i][j]=data;
            data++;
            i--;
        }
        


    }


    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}