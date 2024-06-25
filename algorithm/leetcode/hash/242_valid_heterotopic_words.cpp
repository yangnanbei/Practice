#include "hash_template.hpp"
/* gonna flexibel about stl */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())  {
            return false;
        }
        std::unordered_map<char, int>  um;
        for (auto c1 : s) {
            cout << "c1 is " << c1 << " ";
            um[c1] += 1;
        }
        cout << endl;
        for (auto c2 : t) {
            cout << "c2 is " << c2 << " ";
            um[c2] -= 1;
        }
        cout << endl;

        for (auto kv: um) {
            cout << "first: " << kv.first << " second: " << kv.second << endl;
            if (kv.second) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::string str1 = {"ababa"};
    std::string str2 = {"aaaba"};
    int res = s.isAnagram(str1, str2);
    cout << "res is " << res << endl;
    return 0;
}