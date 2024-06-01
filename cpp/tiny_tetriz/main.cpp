#include <iostream>

using namespace std;

int main() {
	cout << "\033[5;10H" << "\033[38;5;214m" << "hello world" << "\033[10;1H";
	return 0;
}
