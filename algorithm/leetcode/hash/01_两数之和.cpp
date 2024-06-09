
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int tar_val = target - nums[i];
            if(mp.count(tar_val)) {
                return {mp[tar_val], i};
            } else {
                mp.insert(pair<int, int>(nums[i], i));
            }
        }
        return {};
    }
};