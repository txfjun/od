#include <stdio.h>
#include<stdlib.h>

void to2(int num,int i)
{
    
    if (num==0)return;
    else
    {   
       
        to2(num/2,i+1);
        printf("i=%d\n",i);
    }
   
}
 


int main()
{

    to2(10,0);
    return 0;

}