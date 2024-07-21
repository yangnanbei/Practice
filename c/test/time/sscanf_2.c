#include <stdio.h>  
  
int main() {  
    const char *input = "2024-07-13-12:02:05_32";
    char timeStr[10]; // 足够存储 "HH:MM:SS" 格式的时间，包括终止的 '\0'  
  
    // 使用 %*[^:]: 跳过直到第一个 ':' 的所有字符  
    // 然后使用 %[^:]: 读取直到下一个 ':' 的所有字符（小时）  
    // 然后使用 %*c 跳过 ':'  
    // 然后使用 %[^:]: 读取直到下一个 ':' 的所有字符（分钟）  
    // 然后使用 %*c 跳过 ':'  
    // 最后使用 %s 读取剩余的秒数（这里使用 %[^\n] 可能会更安全，但因为我们知道格式，%s 也足够）  
    // 注意：由于 sscanf 的行为，我们需要稍微调整策略来适应秒数的提取  
    // 实际上，我们可以使用两个 %[^:]: 和一个 %s，但第二个 %[^:]: 需要限制长度为2（分钟）  
    // 但为了简单起见，这里使用了一个变通方法，因为我们知道时间格式是固定的  
    int matched = sscanf(input, "%*[^-]-%*[^-]-%*[^-]-%9[^ \t\n]", timeStr);
  
    // 注意：上面的格式字符串中，%8[^ \n] 限制了读取的字符数为8（HH:MM:SS 的长度），  
    // 并确保不会读取换行符（尽管在这个特定的例子中不是必需的）。  
    // 但是，更安全的做法是使用两个 %[^:]: 和一个 %2s，但这样会使格式字符串更复杂。  
  
    // 检查是否成功匹配  
    if (matched == 1) {  
        printf("Matched time: %s\n", timeStr);  
    } else {  
        printf("Failed to match time.\n");  
    }  
  
    return 0;  
}  
  
// 注意：上面的代码有一个潜在的问题，即它假设了输入格式严格为 "YYYY-MM-DD-HH:MM:SS"。  
// 如果输入格式略有不同（例如，日期部分有更多或更少的分隔符），则可能需要调整格式字符串。  
// 一个更健壮的方法是使用多个 %[^:]: 精确匹配小时、分钟和秒，但这样会使代码更复杂。  
  
// 更精确的版本（虽然更复杂）：  
// int matched = sscanf(input, "%*[^-]-%*[^-]-%*[^-]-%2[^:]:%2[^:]:%2s", hours, minutes, seconds);  
// 但这需要你为小时、分钟和秒分别声明变量（如 char hours[3], minutes[3], seconds[3];），  
// 并且处理这些字符串而不是一个组合的时间字符串。