#include <iostream>

static int i = 1;
using namespace std;

template<typename T>
void print(T & t) {
	std::cout << "lvalue ref" << std::endl;
}

template<typename T>
void print(T && t) {
	std::cout << "rvalue ref" << std::endl;
}

template<typename T>
void testForward(T && v) {
	std::cout<< "call testForward " << i++ << " times" << std::endl;
	print(v); /* lvalue */
	print(std::forward<T>(v)); /* guess what */
	print(std::move(v)); /* rvalue */
}

int main() {
	int x = 1;
	testForward(x); /* pass in lvalue */
	testForward(std::move(x)); /* pass in rvalue */

}
