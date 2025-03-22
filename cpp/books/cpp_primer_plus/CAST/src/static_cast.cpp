#include <iostream>

int main()
{
    char ch{ 97 }; // 97 is ASCII code for 'a'
    std::cout << "a has char " << ch << std::endl;
    std::cout << "a has value " << static_cast<int>(ch) << std::endl;

    return 0;
}
