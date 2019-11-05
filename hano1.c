#include<stdio.h>
#include<stdlib.h>

double hanocount(double n)
{
    double res=0;
    if (n<0)return -1;
    if (n==1) return res=1;
    else
    {
        res=hanocount(n-1)*2+1;
    }
 
}

int main()
{

    printf("%ld\n",hanocount(64));

    return 0;
}