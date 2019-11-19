#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{ 

   int status;
   pid_t pid;
   char path[50]="/home/feijun/Desktop/od/hano";
   printf("test execl:\n");
   pid = fork();
   if(pid==0)
   {
   execl(path,"hano",NULL);
   }

  
 waitpid(pid,&status,0); 
   printf("end Execl!\n");
   return 0;
}
