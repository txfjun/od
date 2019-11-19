#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
   FILE *fp;
   fp=popen("ifconfig","r");
   while(!feof(fp))
{
    char buf[100];
    fgets(buf,100,fp);
    if(strstr(buf,"192.168"))
    {
        printf("%s",buf);
    }
}


   pclose(fp);


}