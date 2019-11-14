#include<stdio.h>
#include<stdlib.h>


int main()
{
    char str[20]={0};
    scanf("%[^\n]",str);
    int i=0,j=0;
 //   char *p=str;
    while(str[i]!='\0')
    {
        str[i]=str[j];
        if(str[i]!=32)
        {
            i++;
        }
        j++;
    }


    printf("%s\n",str);


}