#include <iostream>
#include <string>

template<class T>
void show_type(T t)
{
    std::cout << typeid(t).name() << std::endl;
}

template<class T>
void normal_forwarding(T t)
{
    show_type(t);
}

template<class T>
void ref_forwarding(T &t)
{
    show_type(t);
}

template<class T>
void const_ref_forwarding(const T &t)
{
    show_type(t);
}

template<class T>
void perfect_forwarding(T &&t)
{
    show_type(std::forward<T>(t));
}

std::string get_string()
{
    return "hello";
}

int main()
{
    std::string s = "hello world";
    normal_forwarding(s);
    perfect_forwarding(s);
    //normal_forwarding(get_string());
}