#include "hash_template.hpp"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (!nums1.size() || !nums2.size()) {
            return {};
        }
        unordered_map<int, int> um;
        unordered_set<int> result_set;
        for (auto i : nums1) {
            um[i] = 1;
        }
        for (auto nums2_val: nums2) {
            if (um[nums2_val]) {
                result_set.insert(nums2_val);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,5,6,213,54325,12346,124,7,8,9,324,21,343};
    vector<int> nums2 = {1,22,33,44,213,124,77,5543};
    vector<int> res = s.intersection(nums1, nums2);
    for (auto val:res) {
        cout << val << " ";
    }
    cout << '\n';
    return 0;
}