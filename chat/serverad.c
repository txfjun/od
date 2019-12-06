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
char readbuf[1024]={0};
char sendbuf[1024]={0};
struct clientsock{
	int sock;
	struct clientsock *next;
	struct sockaddr_in *clientaddr;
};
struct clientsockhead {
	int size;
	struct clientsock *next;	
};


void *readthread(void *clientsock);//read message using readthread;

void *writethread(void *clientsock);//write message using writethread;

void insertlist(struct clientsockhead *head,struct clientsock *clientsock);

int main()
{
	int sock;// sock for socket, bind , listen 
	int clientsock;
	pthread_t pid_read,pid_send,pid_client;//for creating thread;
	unsigned long inaddr;//address of ip;
	socklen_t serverlenth,clientlenth;
	struct sockaddr_in server,client; //server and client address struct;
	struct clientsock *cltsock;  //thread parameter using struct,read address and ip;
	struct clientsockhead *sockhead;
	memset(&server,0,sizeof(server));//set 0
	memset(&client,0,sizeof(client));
	sockhead = (struct clientsockhead *)malloc(sizeof(struct clientsockhead));
	sockhead->next=NULL;
	sockhead->size=-1;
	
	//set server
	inaddr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_addr.s_addr=inaddr;
	server.sin_port = htons(10088);
	serverlenth = sizeof(server);
	clientlenth = sizeof(client);
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("create sock error\n");
		return -1;
	}
	bind(sock,(struct sockaddr*)&server,serverlenth);
	listen(sock,5);
	printf("server is running\n");
	while(1)
	{
		clientsock=accept(sock,(struct sockaddr *)&client,&clientlenth);
		cltsock=(struct clientsock *)malloc(sizeof(struct clientsock));
		memset(cltsock,0,sizeof(struct clientsock));
		cltsock->sock = clientsock;
		cltsock->clientaddr = &client;
		cltsock->next=NULL;
		insertlist(sockhead,cltsock);
		pthread_create(&pid_read,NULL,readthread,(void*)cltsock);
		pthread_create(&pid_send,NULL,writethread,(void*)cltsock);
		

	}
	close(sock);

	return 0;
}

void *readthread(void *clientsock)//read message using readthread;
{
	
	char ip[100]={0};
	int sock;
	struct sockaddr_in clientaddr;
	struct clientsock *cltsock =(struct clientsock*)clientsock;
	sock = cltsock->sock;
	clientaddr = *(cltsock->clientaddr);
	strcpy(ip,inet_ntoa(clientaddr.sin_addr));
	//printf("%s is connect to server\n",ip);
	while(1)
	{

		int n=0;
		n = recv(sock,readbuf,1024,0);
		if(n>0)
		{
			printf("%s,say:%s\n",ip,readbuf);
		//	fflush(stdout);
	//		memset(readbuf,0,sizeof(readbuf));
		}
		usleep(400000);
	}
	close(sock);
	return NULL;
}
void *writethread(void *clientsock)//write message using writethread;
{

	char sendbuf[1024]={0};
	char ip[100]={0};
	int sock;
	struct sockaddr_in clientaddr;
	struct clientsock *cltsock =(struct clientsock*)clientsock;
	sock = cltsock->sock;
//	clientaddr = *(cltsock->clientaddr);
//	strcpy(ip,inet_ntoa(clientaddr.sin_addr));
//	printf("%s is connect to server\n",ip);
	while(1)
	{

		int n=0;
		scanf("%s",sendbuf);
		n = send(sock,sendbuf,1024,0);
		if(n>0)
		{
			printf("serversay:%s\n",sendbuf);
			//fflush(stdout);
			memset(sendbuf,0,sizeof(sendbuf));
		}
		usleep(400000);
	}
	close(sock);

}
void insertlist(struct clientsockhead *head,struct clientsock *clientsock)
{
	if (head->next==NULL)
	{
		head->next=clientsock;
		head->size=1;
	}
	else
	{
		clientsock->next=head->next;
		head->next=clientsock;
		head->size++;
	}
	


}