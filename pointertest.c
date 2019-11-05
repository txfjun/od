#include <stdio.h>
#include <stdlib.h>

int main()
{
   
    int (*p)[4][2];
    int a[4][2]={1,2,3,4,5,6,7,8};
    p = &a;
    printf("p=%p\n",p);
    printf("a=%p\n",a);
    printf("p+1=%p\n",p+1);
    printf("p+2=%p\n",p+2);
    printf("%p\n",(*p)[1]);
    return 0;
}