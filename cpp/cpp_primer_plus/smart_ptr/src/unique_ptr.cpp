#include <memory>
#include <iostream>

int main() {
	std::unique_ptr<int> p1 = std::make_unique<int>(3);
	std::shared_ptr<int> p2 = std::make_shared<int>(4);
	std::cout << "p1 size " << sizeof(p1) << std::endl;
	std::cout << "p2 size " << sizeof(p2) << std::endl;
	return 0;
}
