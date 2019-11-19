#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main()
{
    char* host="baidu.com";
    struct hostent *hp;
    hp = gethostbyname(host);
    printf("%s",inet_ntoa(*(struct in_addr *)(hp->h_addr_list[0])));




    return 0;
}