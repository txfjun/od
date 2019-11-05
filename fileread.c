#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("test.txt","r");
    char buf[1024];
    fgets(buf,1024,fp);
    printf("%s",buf);
    printf("%s","hello");
    return 0;
}