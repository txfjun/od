#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%4d",a[i][j]);
        }
       
         printf("\n");
    }
 printf("\n-----------\n");
int b[4][3]={0};
    for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                b[i][j]=a[j][i];
            }
            
        }


    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%4d",b[i][j]);
        }
      
         printf("\n");
    }
 printf("\n-----------\n");
//int b[4][3]={0};
    for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                b[i][j]=a[j][3-i];
            }
            
        }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%4d",b[i][j]);
        }
      
         printf("\n");
    }


    return 0;
}