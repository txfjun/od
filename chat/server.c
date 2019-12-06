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

//define CLIENTMAX  100
// char readbuf[1024]={0};
// char sendbuf[1024]={0};
//pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
struct clientsock{
	int sock;
	struct clientsock *next;
	struct sockaddr_in *clientaddr;
};
struct clientsock clienthead;  //thread parameter using struct,read address and ip;
void clientsockInit(struct clientsock *cltsock);
void clientsockAdd(struct clientsock *cltsockhead,struct clientsock *node);
void sendtoall(int sock ,struct clientsock *cltsockhead,const char* sendbuf);
void delsock(struct clientsock *head,int sock);
void *readthread(void *clientsock);//read message using readthread;

void *writethread(void *clientsock);//write message using writethread;
//void *serversay(void *p);

int main()
{
	int sock;// sock for socket, bind , listen 
	int clientsock;
	pthread_t pid_read,pid_send,pid_scanf;//for creating thread;
	unsigned long inaddr;//address of ip;
	socklen_t serverlenth,clientlenth;
	struct sockaddr_in server,client; //server and client address struct;
	
	memset(&server,0,sizeof(server));//set 0
	memset(&client,0,sizeof(client));
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
	system("clear");
	printf("server is running\n");
    clientsockInit(&clienthead);
//	pthread_create(&pid_scanf,NULL,serversay,NULL);
	while(1)
	{
		clientsock=accept(sock,(struct sockaddr *)&client,&clientlenth);
		struct clientsock *cltsock=(struct clientsock *)malloc(sizeof(struct clientsock));
		memset(cltsock,0,sizeof(struct clientsock));
		cltsock->sock = clientsock;
		cltsock->clientaddr = &client;
		cltsock->next=NULL;
		clientsockAdd(&clienthead,cltsock);
		pthread_create(&pid_read,NULL,readthread,(void*)cltsock);
//		pthread_create(&pid_send,NULL,writethread,(void*)cltsock);
		

	}
	close(sock);

	return 0;
}

void *readthread(void *clientsock)//read message using readthread;
{
	char readbuf[1024]={0};
    //char sendbuf[1024]={0};
	
	char ip[100]={0};
	int sock;
	struct sockaddr_in clientaddr;
	struct clientsock *cltsock =(struct clientsock*)clientsock;
	sock = cltsock->sock;
	clientaddr = *(cltsock->clientaddr);
	strcpy(ip,inet_ntoa(clientaddr.sin_addr));
//	printf("%s is connect to server\n",ip);
	while(1)
	{
		int n=recv(sock,readbuf,1024,0);		
		if(readbuf[0]=='q'&&readbuf[1]=='u'&&readbuf[2]=='i'&&readbuf[3]=='t')
		{
			strcat(ip," is out!\n");
			printf("%s\n",ip);
			sendtoall(sock,&clienthead,ip);

			close(sock);
			delsock(&clienthead,sock);
			break;

		}
		if(n<0)
		{

			close(sock);
			delsock(&clienthead,sock);
			return NULL;
		}
		if(readbuf[0]>0)
		{
			printf("%s,say:%s\n",ip,readbuf);	
			sendtoall(sock,&clienthead,readbuf);
			memset(readbuf,0,sizeof(readbuf));

		}
			
		memset(readbuf,0,sizeof(readbuf));
		
		usleep(400000);
	    
	}
	return NULL;
}

void clientsockInit(struct clientsock *cltsock)
{
	cltsock->sock=-1;
	cltsock->clientaddr=NULL;
	cltsock->next=NULL;
	printf("clientsock struct init successfullly!\n");

}
void clientsockAdd(struct clientsock *cltsockhead,struct clientsock *node)
{
	char ip[100]={0};
	int sock;
	sock=node->sock;
	struct sockaddr_in clientaddr;
	clientaddr=*(node->clientaddr);
	strcpy(ip,inet_ntoa(clientaddr.sin_addr));
	if(cltsockhead->next==NULL)
	{
		cltsockhead->next=node;

		printf("%s add and sock=%d!\n",ip,sock);
	}
	else
	{
		node->next=cltsockhead->next;
		cltsockhead->next=node;
		printf("%s add and sock=%d!\n",ip,sock);
	}
	
}

void sendtoall(int sock,struct clientsock *cltsockhead,const char* sendbuf)
{

	if (cltsockhead->next==NULL)
	{
		printf("error!\n");
		exit;
	}
	else {
		struct clientsock * temp;
		temp=cltsockhead->next;
		while(temp!=NULL)
		{
			if(temp->sock!=sock)

			{
				//printf("sock is %d,and message is %s\n",temp->sock,sendbuf);
				send(temp->sock,sendbuf,1024,0);
			}
			temp=temp->next;
		}
	}

}


void delsock(struct clientsock *head,int sock)
{

	char ip[100]={0};	
	
	struct sockaddr_in clientaddr;


	if (head->next==NULL)
	{
		printf("error!\n");
		exit;
	}
	else {
		struct clientsock * temp=NULL;
		struct clientsock * deltemp=NULL;
		temp=head->next;
		while(temp!=NULL)
		{
			if(temp->sock==sock)

			{
				deltemp=temp;
				if(deltemp->next!=NULL)
				{
					temp=deltemp->next;
					clientaddr=*(deltemp->clientaddr);
					strcpy(ip,inet_ntoa(clientaddr.sin_addr));				
					printf("client sock %d is closed\n",sock);
					printf("ip %s is out!\n",ip);
					free(deltemp);
				}
				
				
			}
			temp=temp->next;
		}
	}



}
//void *writethread(void *clientsock)//write message using writethread;
//{
//
////	char sendbuf[1024]={0};
//	char ip[100]={0};
//	int sock;
//	struct sockaddr_in clientaddr;
//	struct clientsock *cltsock =(struct clientsock*)clientsock;
//	sock = cltsock->sock;
////	clientaddr = *(cltsock->clientaddr);
////	strcpy(ip,inet_ntoa(clientaddr.sin_addr));
////	printf("%s is connect to server\n",ip);
//	while(1)
//	{
//
//		int n=0;
//		if(strlen(sendbuf)>0)
//		{
//				n = send(sock,sendbuf,1024,0);
//		if(n>0)
//		{
//			printf("serversay:%s\n",sendbuf);
//			//fflush(stdout);
////			memset(sendbuf,0,sizeof(sendbuf));
//		}
//		}
//	//	scanf("%s",sendbuf);
//	    if (n<0)close(sock);
//		usleep(400000);
//	}
//	
//	return NULL;
//}
//void *serversay(void *p)
//{   
//
//	while(1)
//	{
//	    memset(sendbuf,0,sizeof(sendbuf));
//		scanf("%s[^\n]",sendbuf);
//		usleep(500000);
//	}
//
//	
//}
