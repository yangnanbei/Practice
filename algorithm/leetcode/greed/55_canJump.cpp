class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ability_reach_index = 0;
        int end = nums.size() - 1;
        if (nums.size() == 1) return true;
        for (int i = 0; i <= ability_reach_index; i++) {
            ability_reach_index = max(i + nums[i], ability_reach_index);
            if (ability_reach_index >= end) 
                return true;
        }
        return false;
    }
};
