#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void run1()
{	
	int i=0;
	while(1)
	{
		printf("%80d\r\n",i++);
		fflush(stdout);
		printf("\r\033[k");
		usleep(5000000);
		fflush(stdout);
	}
}
void run()
{	
	int i=0;
	while(1)
	{
		printf("%40d\r",i++);
		fflush(stdout);
		usleep(3500000);
	}
}


int main()
{
	int i=0;
	pid_t pid,pid1;
    	pid=fork();
	pid1=fork();
	if(pid==0)
	{
		run();
	}
	
	if(pid1==0)
	{
		run1();
	}
	while(1)
	{
		printf("%d\r",i++);
		fflush(stdout);
		usleep(2000000);
	}
	return 0;
}
