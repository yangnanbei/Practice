#include <iostream>

int main()
{
    int i = 0;
    const int ci = i;
    i = 42;

    // ci = 42;
    std::cout << ci << std::endl;

    const int &r1 = i;
    // r1 = 42;
    std::cout << r1 << std::endl;

    const int &r2 = ci;
    // r2 = 42;
    std::cout << r2 << std::endl;

    // ci = 42;
    std::cout << ci << std::endl;
    return 0;
}