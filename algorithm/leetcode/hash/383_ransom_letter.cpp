#include "common.hpp"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        int hash[26] = {};

        for (auto val_mag: magazine) {
            hash[ val_mag  - 'a' ] += 1;
        }
        for (auto val_rans: ransomNote) {
            //cout << "val_rans is " << val_rans;
            hash[ val_rans  - 'a' ] -= 1;
        }

        for (auto val: hash) {
            if (val < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::string magazine = "abcdededcacsxc";
    std::string ransomNote = "abc";
    cout << "res is " << s.canConstruct(ransomNote, magazine) << endl;
    std::string src1 = "aaa";
    std::string dest1 = "abc";
    cout << "res is " << s.canConstruct(dest1, src1) << endl;
    return 0;
}
