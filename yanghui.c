#include <stdio.h>
#include <stdlib.h>
#define  N 10

// void yanghui(int a[N][N])
// {
//     for(int i=0;i<N;i++)
//     {
//         for(int j=0;j<N;j++)
//         {
//             if(i==0||i==j)
//             {
//                 a[i][j]=1;
//             }
//             else
//             {
//                 /* code */
//                 a[i][j]=a[i-1][j-1]+a[i-1][j];
//             }
            
//         }
//     }
// }


// void printyanghui(int a[N][N])
// {
//     for(int i=0;i<N;i++)
//     {
//         for(int j=0;j<i;j++)
//         printf("%3d",a[i][j]);
//         printf("\n");
//     }
// }


int main()
{
    int a[N][N]={0};
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0||i==j)
            {
                a[i][j]=1;
            }
            else
            {
                /* code */
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
            
        }
    }
  

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        printf("%3d",a[i][j]);
        printf("\n");
    }
    for(int i=0;i<N;i++)
    {
        printf("%*d",20-i*2,a[i][0]);
        for(int j=1;j<=i;j++)
        {
            printf("%4d",a[i][j]);

        }
        printf("\n");
    }


    return 0;
}