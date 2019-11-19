#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int fd[2];
	pid_t pid;
	int status;
	pipe(fd);
	pid = fork();
	if(pid==0)
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
		
	
	}else
	{   
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);

//		waitpid(pid,&status,0);

	}
	printf("end\n");
	return 0;
}
