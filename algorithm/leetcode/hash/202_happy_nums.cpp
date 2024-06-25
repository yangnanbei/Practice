#include "hash_template.hpp"
class Solution {
public:
    int getSum(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }

            // if we can find sum
            if (set.find(sum) != set.end()) {
                return false;
            }
            set.insert(sum);
            n = sum;
        }

    }
};

int main() {
    Solution s;
    int n1 = 19;
    int n2 = 2;
    cout << "n1 is " << s.isHappy(n1) << endl;
    cout << "n2 is " << s.isHappy(n2) << endl;
    cout << "n3 is " << s.isHappy(1) << endl;
    return 0;
}
