#include <stdio.h>
#include<stdlib.h>

int x=0,y=0;

int **init_migong(int length)
{
    int **a;
    a=(int **)malloc(sizeof(int *)*length);
    for(int i=0;i<length;i++)
    {
       a[i]=(int *)malloc(sizeof(int)*length);
        for(int j=0;j<length;j++)
        {
            
            a[i][j]=0;
        }

    }
    
    return a;
}

void show(int **a,int length)
{
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void run(int **arr,char ch)
{
    switch (ch)
    {
    case 'a':
        if((y-1)>=0)
        {
            arr[x][y-1]=1;
            arr[x][y]=0;
            y=y-1;

        }
  
        break;
    case 'd':
        if((y+1)<20)
        {
            arr[x][y+1]=1;
            arr[x][y]=0;
            y=y+1;
        }
        break;
    case 'w':
        if((x-1>=0))
        {
            arr[x-1][y]=1;
            arr[x][y]=0;
            x--;
        }
    case 's':
        if((x+1<=20))
        {
            arr[x+1][y]=1;
            arr[x][y]=0;
            x++;
        }
    default:
        break;
    }
}

int main()
{
    int **arr;
    arr=init_migong(20);
    arr[x][y]=1;
    char ch;
    show(arr,20);
    while(1)
    {
        ch=getchar();
        getchar();
        run(arr,ch);
        show(arr,20);
    }
  

   

    return 0;

}