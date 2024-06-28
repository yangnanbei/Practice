#include "common.hpp"

class Solution {
public:
    void reverseString(vector<char>& s) {
        int length = s.size();
        for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

int main() {

}
