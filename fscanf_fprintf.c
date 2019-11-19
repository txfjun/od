#include<stdio.h>
#include<stdlib.h>
#include

int main()
{ 
    FILE *fp;
    char buff[1024];
    fp = fopen("/home/fscan.txt","w");
    if(fp!=NULL)
    {
        printf("file open error\n");
    }
    else
    {
        fscanf(stdin,"%s",buff);
        fputs(buff,fp);
    }
    fclose(fp);



    return 0;
}