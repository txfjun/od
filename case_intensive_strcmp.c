#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int case_intensive_strcmp(unsigned const char *str1,unsigned const char *str2)
{
	if ((str1==NULL)||(str2==NULL))
	{
		return 1;
	}
	if (str1==str2)
		return 0;
	else
	{
		while(tolower(*str1)==tolower(*str2))
		{
			if(*str1=='\0')
				return 0;

			str1++;
			str2++;
		}
		return *str1-*str2;

	}

}



int main()
{
	char *str1="helloworld";
	char *str2="Helloworld1";
	if(!case_intensive_strcmp(str1,str2))
		printf("same\n");
	else
		printf("Not the same!\n");

	return 0;
}
