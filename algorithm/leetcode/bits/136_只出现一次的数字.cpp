class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        int ans = 0;
        for (auto val:nums) {
            ans ^= val;
        }
        return ans;
    }
};