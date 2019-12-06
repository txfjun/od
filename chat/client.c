#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/time.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/types.h>
#include<pthread.h>

char sendbuf[1024]={0};
char readbuf[1024]={0};
int threadclose=0;
int connectSocket(const char * hostname,int clientport);
void *readthread(void *client)
{
    int clt=*(int*)client;
    while(1)
    {
    
        if(threadclose==1)
        {
            printf("bye!\n");
            close(clt);
            break;
        }
        read(clt,readbuf,sizeof(readbuf));    
           
        printf("Received:%s ",readbuf);  

        memset(readbuf,0,sizeof(readbuf));
       
        
       
       usleep(500000);
    }
   
    return NULL;
}
void *sendthread(void *client)
{
    int clt=*(int*)client;
    while(1)
    {       
	    memset(sendbuf,0,sizeof(sendbuf));
	    printf(">");
        fgets(sendbuf,sizeof(sendbuf),stdin);
       if(sendbuf[0]=='q'&&sendbuf[1]=='u'&&sendbuf[2]=='i'&&sendbuf[3]=='t')
       {
           threadclose=1;
           write(clt,sendbuf,sizeof(sendbuf)); 
           break;
       }
        write(clt,sendbuf,sizeof(sendbuf));         
    }
    
    return NULL;
}


int main()
{
    char buf[100]={0};
    int sock;
    connectSocket("127.0.0.1",8888);

    return 0;
}

int connectSocket(const char * hostname,int clientport)
{
    int sock;
    char writebuf[1024]={0};
    char readbuf[1024]={0};
    unsigned long inaddr;
    struct sockaddr_in server;
    struct hostent *hp;
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
  
    server.sin_addr.s_addr=inet_addr(hostname);
    server.sin_port = htons(10088);
    sock = socket(AF_INET,SOCK_STREAM,0);
 
    if (sock<0)
    {
   //     printf("sock<0\n");
        return sock;
    }
    socklen_t socklen=sizeof(server);
    int j=connect(sock,(struct sockaddr *)&server,socklen);  
    system("clear");
    printf("client is running!\n");     
  
    pthread_t pid1,pid2;
 
        pthread_create(&pid1,NULL,readthread,&sock);
        pthread_create(&pid2,NULL,sendthread,&sock);
        pthread_join(pid1,NULL);
        pthread_join(pid2,NULL);
    
   // close(sock);
    return 0;
    
}



