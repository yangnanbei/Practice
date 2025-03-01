#include <iostream>

class X { 
public: 
    X() { std::cout << "X ctor" << std::endl; } 
    X(const X&x) { std::cout << "X copy ctor" << std::endl; } 
    ~X() { std::cout << "X dtor" << std::endl; } 
    void show() { std::cout << "show X" << std::endl; } 
}; 
 
X make_x() 
{ 
    X x1; 
    return x1; 
} 
 
int main() 
{ 
    int i = 0;
    int &j = i; /* lvalue ref */
    int &&k = 10; /* rvalue ref */
    X &&x2 = make_x(); 
    //X x2 = make_x();
    //x2.show(); 
}

