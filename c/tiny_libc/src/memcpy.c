#include <stdio.h>
#include <string.h>

void* memcpy_(void* dest, void* src, size_t len) {
    void* ret = dest;

    while (len--) {
        *(char *)dest = *(char *)src;
        (char *)dest++;
        (char *)src++;
    }
    return ret;
}

/* test */

#define BUF_SIZE 128

int main() {
    char str[BUF_SIZE] = "myson in the bus!";
    char des[BUF_SIZE];
    memcpy_(des, str, BUF_SIZE);
    printf("%s \n", des);
    return 0;
}