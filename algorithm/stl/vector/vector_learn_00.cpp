#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> my_vec = {0};
    my_vec.push_back(1);
    my_vec.push_back(2);
    my_vec.push_back(3);
    my_vec.push_back(4);
    my_vec.push_back(5);
    my_vec.push_back(6);
    my_vec.push_back(7);
    my_vec.push_back(8);
    my_vec.push_back(9);
    my_vec.push_back(10);
    
    for (auto val: my_vec) {
        cout << val << " ";
    }
    cout << endl;
    
    // 删除第一个元素
    my_vec.erase(my_vec.begin());
    
    // 删除最后一个元素
    my_vec.pop_back();
    
    for (auto val: my_vec) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}