#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<pthread.h>

void* checkip(void *a)

{
	int start,end;
	int *arr = (int*)a;
	start=arr[0];
	end = arr[1];
	for (int i=start;i<end;i++)
	{
		FILE *ph;
		char str[50];
		char buff[1024];
		if(i<255)
		{
	    sprintf(str,"ping -c 1 192.168.3.%d",i);
		ph=popen(str,"r");
		if(ph!=NULL)
		{
		fread(buff,1,1023,ph);
		if(strstr(buff,"time=")!=NULL)
		printf("192.168.3.%d is connected!\n",i);
		fflush(stdout);
		}
		pclose(ph);
		}
	
	}
}

int main()
{
    pthread_t pid[10];
	int a[2]={1,20};
	pthread_create(&pid[1],NULL,checkip,a);   
    pthread_join(pid[1],NULL);  

	return 0;
}

