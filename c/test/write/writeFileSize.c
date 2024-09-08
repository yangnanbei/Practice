#include <stdio.h>  
#include <stdlib.h>  
#include <fcntl.h>  
#include <unistd.h>  
#include <string.h>  
  
int main() {  
    int fd; // 文件描述符  
    const char* filePath = "write_len_test.pcap";  
    const char* content = "Hello, this is a test string written using write system call.\n";  
    ssize_t bytesWritten; // 用于存储write函数的返回值  
  
    // 打开（或创建）文件  
    fd = open(filePath, O_WRONLY | O_CREAT | O_TRUNC, 0666);  
    if (fd == -1) {  
        perror("Failed to open file");  
        exit(EXIT_FAILURE);  
    }  
  
    // 使用write函数写入数据  
    bytesWritten = write(fd, content, strlen(content));  
    if (bytesWritten == -1) {  
        perror("Failed to write to file");  
        close(fd); // 出错时关闭文件  
        exit(EXIT_FAILURE);  
    }  
  
    printf("Successfully wrote %zd bytes to %s\n", bytesWritten, filePath);  
  
    // 关闭文件描述符  
    close(fd);  
  
    return 0;  
}
