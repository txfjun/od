/******************************************
 * Filename : client.c
 * Purpose  : connect to localhost 7000 and output anything received
 * Author   : Simon Amor (simon@leaky.org)
 * 
 * Warning  : This code is not fully functional - it's also not my usual
 *            coding style. Converting this to a set of functions is left
 *            as an exercise to the reader ;-)
 ***/

/*
 * WARNING: THIS CODE IS ONLY PARTIALLY FUNCTIONAL
 */

#include <stdio.h>
/* for EXIT_FAILURE and EXIT_SUCCESS */
#include <stdlib.h>

#define TRUE   1
#define FALSE  0

/* network functions */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
/* FD_SET, FD_ISSET, FD_ZERO macros */
#include <sys/time.h>

int main()
{
  int opt=TRUE;
  int client_socket;
  struct sockaddr_in address;
  int addrlen;
  struct hostent *hostaddr;

  int valread;
  char buffer[1025];    /* data buffer of 1K */

/* create the master socket and check it worked */
  if ((client_socket = socket(AF_INET,SOCK_STREAM,0))==0) {
/* if socket failed then display error and exit */
    perror("Create client_socket");
    exit(EXIT_FAILURE);
  }

/* type of socket created */
  address.sin_family = AF_INET;
  inet_pton(AF_INET, "127.0.0.1", (void *)&address.sin_addr);
/* 7000 is the port to use for connections */
  address.sin_port = htons(7000);
/* bind the socket to port 7000 */
  if (connect(client_socket, (struct sockaddr *)&address, sizeof(address))<0) {
/* if bind failed then display error message and exit */
    perror("connect");
    exit(EXIT_FAILURE);
  }

  while (1==1) {
/* wait for connection, forever if we have to */
    valread = recv(client_socket, &buffer, 1024, 0);
    if (valread < 0) {
      perror("recv");
      exit(0);
    } else if (valread == 0) {
      printf("Closing connection\n");
      exit(0);
    }
/* set the terminating NULL byte on the end of the data read */
    buffer[valread] = '\0';
    printf("Received data:%s:\n", buffer);
  }

/* normally you should close the sockets here before program exits */
/* however, in this example the while() loop prevents getting here */
}
