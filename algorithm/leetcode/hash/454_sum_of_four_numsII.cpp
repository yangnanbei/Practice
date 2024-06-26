#include "hash_template.hpp"

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> um;
        int res = 0;
        for (auto val1: nums1) {
            for (auto val2: nums2) {
                um[val1 + val2] += 1;
            }
        }

        for (auto val3: nums3) {
            for (auto val4: nums4) {
                if (um.find(0 - (val3 + val4)) != um.end()) {
                    res += um[0 - (val3 + val4)];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;

    //输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
    //输出：2
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {-1, -2};
    std::vector<int> nums3 = {-1, 2};
    std::vector<int> nums4 = {0, 2};
    cout << "res is " << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    
    return 0;
}