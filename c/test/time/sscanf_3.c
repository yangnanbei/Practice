#include <stdio.h>  
  
int main() {  
    const char *input = "/home/ge/data/pcap/traffic-collect/20240713-120200_1.pcap";  
    char timeStr[32]; // 足够存储 "120200" 和终止的 '\0'  
  
    // 使用 %*[^_] 跳过直到第一个 '_' 的所有字符（但这里我们实际上想要的是 'wri_' 之后的部分）  
    // 然后使用 %*[^-] 跳过 'wri_' 后面的所有非 '-' 字符（即日期部分）  
    // 接着使用 %*[-] 跳过日期和时间戳之间的 '-'  
    // 最后使用 %6s 读取接下来的 6 个字符（即时分秒部分）  
    int matched;  
    // 注意：上面的 %*[^/] 实际上是不正确的，因为它会尝试匹配除了 '/' 之外的任何字符直到 'wri_'  
    // 但由于 'wri_' 的位置是固定的，并且前面是文件夹名，我们可以简单地使用更长的前缀或更复杂的逻辑来跳过  
    // 一个更简单且正确的方法是使用更长的前缀匹配，但这里为了说明目的，我们保持原样并指出其不正确性  
    // 正确的做法可能是使用更具体的路径前缀匹配，或者依赖于 'wri_' 后紧跟日期的模式  
  
    // 由于上面的 %*[^/]wri_%*[^-] 是不准确的，我们改用更简单的逻辑，直接定位到 'wri_' 后面的日期和时间戳  
    // 注意：这里我们假设 'wri_' 后面紧跟的是日期，然后是 '-'，然后是我们要找的时间戳  
    //matched = sscanf(input, "%*[^/]*/wri_%*[^-]-%6s", timeStr);  
    // 但是，上面的模式仍然过于复杂且可能不是最高效的。一个更简单且直接的方法是：  
    //matched = sscanf(input, "*%5[wri_]*[^-]-%6s", timeStr);  
    // 这里我们使用了 '*' 来匹配任意数量的字符（除了换行符），直到遇到 '/wri_'，然后跳过日期直到 '-'，最后读取时间戳  
	matched = sscanf(input, "%*[^-]%*[^/]/%16s", timeStr);  
	//matched = sscanf(input, "%*[^-]*%*[^-]-%6s", timeStr);  
        printf("Matched time: %s\n", timeStr);  
    // 检查是否成功匹配  
    if (matched == 1) {  
        printf("Matched time: %s\n", timeStr);  
    } else {  
        printf("Failed to match time.\n");  
    }  
  
    return 0;  
}
