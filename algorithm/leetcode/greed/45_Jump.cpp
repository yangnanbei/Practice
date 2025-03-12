class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_distance = 0;
        int max_distance = 0;
        int res = 0;
        int length = nums.size();

        if (nums.size() <= 1) {
            return 0;
        }

        for (int i = 0; i < length - 1; i++) {
            max_distance = max(nums[i] + i, max_distance);
            if (i == cur_distance) {
                res += 1;
                cur_distance = max_distance;
                cout << "now res is " << res << " cur dis is " << cur_distance << " max dis is " << max_distance << endl;
            }
        }
        return res;
    }
};
