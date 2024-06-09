#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> hash;
    hash["hello"] = 10;
    hash["world"] = 20;
    hash["hello"] = 30;
    cout << hash["hello"] << endl; // 输出30
    cout << hash["world"] << endl; // 输出20

    unordered_map<int, int> hash2;
    hash2[1] = 10;
    hash2[2] = 20;
    hash2[3] = 30;
    cout << hash2[1] << endl; // 输出10
    cout << hash2[2] << endl; // 输出20
    cout << hash2[3] << endl; // 输出30
    hash.clear();
    
    std::unordered_map<std::string, int> umap = {{"apple", 7}, {"banana", 2}, {"apple", 3}, {"apple", 5}};
    int apple_cnt = umap.count("apple");
    cout << "apple cnt is " << apple_cnt << std::endl; // is 1
    cout << "banana cnt is " << umap.count("banana") << std::endl; // is 1
    cout << "orange cnt is " << umap.count("orange") << std::endl; // is 0
    
    // iterator
    std::unordered_map<std::string, int> umap2 = {{"apple", 1}, {"banana", 2}, {"orange", 3}};

    for (const auto& kv : umap2) {
        std::cout << "Key: " << kv.first << ", Value: " << kv.second << std::endl;
    }

    return 0;
}