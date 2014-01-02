#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
 
//以下头文件是为了使样例程序正常运行
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    struct sockaddr_in pin;
    struct hostent *nlp_host;
    int sock; 
    int port;

    port=8000;
    nlp_host=gethostbyname("192.168.199.228");
     
    pin.sin_family=AF_INET;
    pin.sin_addr.s_addr=((struct in_addr *)(nlp_host->h_addr))->s_addr;
    pin.sin_port=htons(port);
     
    //建立socket
    sock=socket(AF_INET,SOCK_STREAM,0);
     
    connect(sock,(struct sockaddr*)&pin,sizeof(pin));

    printf("send: hi!\n");
    send(sock,"hi!",strlen("hi!"),0);

    char buf[2048];
    int numbytes;
    numbytes=recv(sock, buf, 2048, 0);
    printf("numbytes: %d\n", numbytes);
    buf[numbytes] = '\0';
    printf("received: %s\n",buf);
    close(sock);
    return 0;
}