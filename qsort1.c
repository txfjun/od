#include<stdio.h>
#include<stdlib.h>


void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b=temp;
}


void quicksort(int *a,int left,int right)
{
    int i=left,j=right;
    int key = a[left];
    while (i<j)
    {
        while(i<j && a[j]>=key)
        {
            j--;
        }
        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
        while(i<j&&a[i]<key)
        {
            i++;
        }
        if(i<j)
        {
            swap(&a[j],&a[i]);
        }
        a[i]=key;
        quicksort(a,left,i-1);
        quicksort(a,i+1,right);
    }
    



}



void show (int *a)
{
    for(int i=0;i<10;i++)
    {
        printf("%4d",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[10]= {5,5,6,8,9,5,0,3,0,10};
    quicksort(a,0,9);
    show(a);

    return 0;
}