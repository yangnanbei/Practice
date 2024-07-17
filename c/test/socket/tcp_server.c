#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <netinet/in.h>  
#include <sys/socket.h>  
  
#define PORT 8080  
  
int main() {  
    int server_fd, new_socket;  
    struct sockaddr_in address;  
    int opt = 1;  
    int addrlen = sizeof(address);  
    char buffer[1024] = {0};  
    char *hello = "Hello from server";  
  
    // 创建 socket 文件描述符  
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {  
        perror("socket failed");  
        exit(EXIT_FAILURE);  
    }  
  
    // 绑定 socket 到端口 8080  
    address.sin_family = AF_INET;  
    address.sin_addr.s_addr = INADDR_ANY;  
    address.sin_port = htons(PORT);  
  
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {  
        perror("bind failed");  
        exit(EXIT_FAILURE);  
    }  
  
    // 监听端口  
    if (listen(server_fd, 3) < 0) {  
        perror("listen");  
        exit(EXIT_FAILURE);  
    }  
  
    // 等待客户端连接  
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {  
        perror("accept");  
        exit(EXIT_FAILURE);  
    }  
  
    // 读取客户端发送的数据  
    read(new_socket, buffer, 1024);  
    printf("%s\n", buffer);  
  
    // 发送数据到客户端  
    send(new_socket, hello, strlen(hello), 0);  
    printf("Hello message sent\n");  
  
    // 关闭socket  
    close(new_socket);  
    close(server_fd);  
  
    return 0;  
}
