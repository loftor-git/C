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

int main(int argc, char **argv)
{
    int serverSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
     
    // 用port保存使用的端口
    int port=8000;
     
    // 建立Socket，并设置
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
     
    // 设置socket选项，这是可选的，可以避免服务器程序结束后无法快速重新运行
    int val=1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
     
    // 定义端口和监听的地址
    serverAddr.sin_family      = AF_INET;
    serverAddr.sin_port        = htons(port);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    memset(&(serverAddr.sin_zero), 0, 8);
    int rc = bind(serverSocket, (struct sockaddr*) &serverAddr,sizeof(struct sockaddr));
     
    // 让serverSocket开始监听，客户队列长为5
    rc = listen(serverSocket, 5);
     
    // 等待客户连接
    int sock;
    int clientAddrSize = sizeof(struct sockaddr_in);
    while(1){
        sock = accept(serverSocket,(struct sockaddr*) &clientAddr,(socklen_t*) &clientAddrSize);
        char buf[2048];
        int numbytes;
        numbytes=recv(sock, buf, 2048, 0);
        printf("numbytes: %d\n", numbytes);
        buf[numbytes] = '\0';
        printf("received: %s\n",buf);
        printf("send: hello world!\n");
        send(sock,"hello world!hello world!hello world!hello world!hello world!hello world!",strlen("hello world!hello world!hello world!hello world!hello world!hello world!"),0);
        close(sock);
    }
    return 0;
}