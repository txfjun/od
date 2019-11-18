#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

void checkip(int start,int end)
{
	for (int i=start;i<end;i++)
	{
		FILE *ph;
		char str[50];
		char buff[1024];
		sprintf(str,"ping -c 1 192.168.3.%d",i);
		ph=popen(str,"r");
		if(ph!=NULL)
		{
		fread(buff,1,1023,ph);
		if(strstr(buff,"time=")!=NULL)
		printf("192.168.3.%d is connected!\n",i);
		}
		pclose(ph);
	}
}

int main()
{
    int status[5];
	pid_t pid[5];

    for(int i=0;i<5;i++)
	{
		pid[i]=fork();
	}
		
	if(pid[1]==0)
	{
		checkip(50,100);

	}
	if(pid[2]==0)
	{
		checkip(100,150);
		
	}
	if(pid[3]==0)
	{
		checkip(150,200);
		
	}
	if(pid[4]==0)
	{
		checkip(200,255);
		
	}
	if(pid[0]==0)
	{
		checkip(1,50);
		
	}


    waitpid(pid[0],&status[0],0);
	waitpid(pid[1],&status[1],0);
	waitpid(pid[2],&status[2],0);
	waitpid(pid[3],&status[3],0);
	waitpid(pid[4],&status[4],0);
	return 0;
}

