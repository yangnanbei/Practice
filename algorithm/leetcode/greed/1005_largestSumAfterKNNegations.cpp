class Solution {
static bool cmp(int a, int b) {
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0;
        int min_num = INT_MIN;
        sort(nums.begin(), nums.end(), cmp);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k-- > 0) {
                nums[i] *= -1;
            }
        }

        if (k % 2 == 1) nums[nums.size() - 1] *= -1;

        for (int val: nums) res += val;
        return res;
    }
};
