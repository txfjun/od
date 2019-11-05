#include <stdio.h>
#include<stdlib.h>

int a[10][3]={0};
int num=1;
int imov=0;
void input()
{
  
    printf("Please input the number 0-9:\n");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        a[9-i][0]=num-i;
    }
}


void show (int a[10][3])
{
    printf("%5c%5c%5c\n",'A','B','C');
    printf("-------------------\n");
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<3;j++)
        printf("%5d",a[i][j]);
        printf("\n");
    }
   
}

void move(int a[10][3],char A, char C)
{
    printf("%c----->%c\n",A,C);
    int n,m;
    n=(int)A-65;
    m=(int)C-65;
    // printf("n=%d",n);
    // printf("n=%d",m);
    int i,j;
    for(i=0;i<10;i++)
    {
        if(a[i][n]!=0)
        {
         //   printf("i=%d",i);
             break;
        }
        
      
    }
    j=9;
    do
    {
        if(a[j][m]==0)
        {
          //  printf("j=%d",j);
            break;
        }
        j--;
        /* code */
    } while (j>=0);
    
   
    // for(j=0;j<0;j++)
    // {
    //     if(a[j][m]==0)
    //     {
    //         printf("j=%d",j);
    //         break;
    //     }
        
    // }
  
    int temp=a[j][m];
    a[j][m]=a[i][n];
    a[i][n]=temp;
    imov++;
    show(a);

}
void hano(int num,char A,char B,char C)
{
     if (num==1)
     move(a,A,C);
     else
     {
         hano(num-1,A,C,B);
         move(a,A,C);
         hano(num-1,B,A,C);
         
     }
     


}



int main()
{
    input();
    show(a);
    // move(a,'A','C');
    // move(a,'A','B');
    // move(a,'A','C');
    hano(num,'A','B','C');

    printf("The total of moving is :%d\n",imov);
    return 0;
}