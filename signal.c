#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handle(int num)
{
    printf("i won't die\n");

}

int main()
{
	signal(SIGINT,handle);
	while(1)
	{

		printf("test %d!\n",getpid());
		sleep(1);
	}

	return 0;
}

