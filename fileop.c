#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("test.txt","w");
    fputs("This is a test file!\n",fp);
    fclose(fp);


    return 0;
}