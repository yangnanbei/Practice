#include <iostream>
#include <cstring>

void foo(int &&i) {} //i是右值引用

template<class T>
void bar(T &&t) {} //t是万能引用

int get_val()
{
    return 1;
}

int main()
{
    int &&x = get_val(); //右值引用
    auto &&y = get_val(); //万能引用
}


