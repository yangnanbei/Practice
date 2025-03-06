class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int cur_cnt = 0;
        for (auto val: nums) {
            cur_cnt += val;
            if (cur_cnt > res) {
                res = cur_cnt;
            }
            if (cur_cnt <= 0) {
                cur_cnt = 0;
            }
        }
        return res;
    }
};
