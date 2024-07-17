#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
  
#define PORT 8080  
  
int main() {  
    struct sockaddr_in serv_addr;  
    int sock = 0, valread;  
    struct sockaddr_in serv_addr2;  
    char *hello = "Hello from client";  
    char buffer[1024] = {0};  
  
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {  
        printf("\n Socket creation error \n");  
        return -1;  
    }  
  
    serv_addr.sin_family = AF_INET;  
    serv_addr.sin_port = htons(PORT);  
  
    // 将IPv4地址从文本转换成二进制形式  
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) {  
        printf("\nInvalid address/ Address not supported \n");  
        return -1;  
    }  
  
    // 连接到服务器  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {  
        printf("\nConnection Failed \n");  
        return -1;  
    }  
  
    // 发送数据到服务器  
    send(sock, hello, strlen(hello), 0);  
    printf("Hello message sent\n");  
  
    // 接收来自服务器的数据  
    valread = read(sock, buffer, 1024);  
    printf("%s\n", buffer);  
  
    // 关闭socket  
    close(sock);  
    return 0;  
}
