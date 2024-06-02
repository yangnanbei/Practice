#include <iostream>
#include <memory>

// 智能指针
// 引用计数
// 共享所有权的智能指针
// 复制构造函数

int main()
{
    std::shared_ptr<int> p1(new int(42));
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl; // 输出2
    std::shared_ptr<int> p2 = p1; // 引用计数加1
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl; // 输出2
    std::cout << "p2.use_count() = " << p2.use_count() << std::endl; // 输出2

    /* 复制构造函数创建新的shared_ptr */
    std::shared_ptr<int> p3(p1); // 引用计数加1
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl; // 输出3
    std::cout << "p3.use_count() = " << p3.use_count() << std::endl; // 输出3

    return 0;
}