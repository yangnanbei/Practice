#define SIZE 100
#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig) {
    void *array[SIZE];
    size_t size;

    // 获取所有调用的地址
    size = backtrace(array, SIZE);
    printf("Signal caught! Stack trace:\n");

    // 转换地址为可读的字符串
    char **strings = backtrace_symbols(array, size);
    if (strings == NULL) {
        perror("backtrace_symbols");
        exit(EXIT_FAILURE);
    }

    // 打印调用堆栈
    for (size_t i = 0; i < size; i++) {
        printf("%s\n", strings[i]);
    }
    free(strings);
    exit(0);
}

void func_3() {
    raise(SIGTRAP); // 触发信号，打印调用堆栈
}

void func_2() {
    func_3();
}

void func_1() {
    func_2();
}

int main() {
    signal(SIGTRAP, handler); // 注册信号处理函数
    func_1();
    return 0;
}
