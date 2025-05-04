class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> set(nums.begin(), nums.end());
        int max_len = 0;
        int res = 0;
        for (const int val: set) {
            // need to iterate the set instead of the nums
            // to avoid such arr [1,1,1,1,1,...1,2,3]
            int cur_len = 1;
            if (set.contains(val + 1)) {
                // cut the branch
                continue;
            }
            int minus_nums = 1;
            int nums = 0;
            while (set.contains(val - minus_nums)) {
                minus_nums++;
                nums += 1;
            }
            cur_len += nums;
            max_len = max_len > cur_len? max_len: cur_len;
        }

        return max_len;
    }
};
