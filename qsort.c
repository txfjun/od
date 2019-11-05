#include<stdio.h>
#include<stdlib.h>


void qsort_test(int *a,int start,int end)
{
    if (start >=end) return;
    int i=start,j=end;
    int first=a[i];
    while(i<j)
    {
        while ((i<j)&&(first<=a[j]))
        j--;
        if(i<j)
        a[i++]=a[j];
        while((i<j)&&(first>a[i]))
        i++;
        if(i<j)
        a[j--]=a[i];

    }
    a[i]=first;
    qsort_test(a,start,i-1);
    qsort_test(a,i+1,end);

}

void show (int* a)
{
    for(int i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }

}


int main()
{
    int a[10]={2,5,1,0,4,7,8,4,13,19};
    show(a);
    printf("----------\n");
    qsort_test(a,0,9);
    show(a);

    return 0;
}