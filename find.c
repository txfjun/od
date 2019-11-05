#include<stdio.h>
#include<stdlib.h>

int findarr(int *a,int f,int s,int e)
{
   int mid=(s+e)/2;
   if (a[mid]==f) return mid;
   if (f<a[mid]){
       findarr(a,f,s,mid);
   }
   else{
       findarr(a,f,mid,e);
   }
}
int main()
{
    int a[9]={1,4,5,7,8,10,14,18,20};
    int f=20;
    int s =0;
    int e=9;
    int mid = findarr(a,f,s,e);
    printf("%d",mid+1);
    return 0;
}