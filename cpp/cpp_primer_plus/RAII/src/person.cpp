#include <iostream>
using namespace std;

class Person {
  public:
    Person(const std::string name = "", int age = 0):
    name_(name), age_(age) {
    	std::cout << "Init a person" << std::endl;
    }
    ~Person() {
    	std::cout << "Destory a person" << std::endl;
    }
    const std::string& getName() const {
	return this->name_;
    }
    int getAge() const {
    	return this->age_;
    }
  private:
    const std::string name_;
    int age_;
};

int main() {
    Person P;
    return 0;
}
