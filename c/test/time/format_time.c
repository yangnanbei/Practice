#include <stdio.h>  
#include <time.h>  
#include <stdlib.h>  
  
// 函数：将时间戳转换为 YYYYMMDDHHMMSSmmm 格式的字符串  
// 参数：timestamp - 时间戳（秒）  
//       buffer - 存储转换结果的缓冲区  
//       size - 缓冲区大小  
void timestamp_to_string(time_t timestamp, char* buffer, size_t size) {  
    struct tm* tm_info;  
    // 将时间戳转换为本地时间  
    tm_info = localtime(&timestamp);  
    if (tm_info == NULL) {  
        // 错误处理  
        snprintf(buffer, size, "Error");  
        return;  
    }  
  
    // 使用strftime格式化日期和时间，但不包括毫秒  
    strftime(buffer, size, "%Y%m%d%H%M%S", tm_info);  
  
}
  
int main() {  
    time_t current_time;  
    char time_str[32]; // 确保这个缓冲区足够大以存储结果  
  
    // 获取当前时间的时间戳  
    time(&current_time);  
  
    // 转换时间戳  
    timestamp_to_string(current_time, time_str, sizeof(time_str));  
  
    // 打印结果  
    printf("Current time: %s\n", time_str);  
  
    return 0;  
}
