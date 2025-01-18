class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    void back_tracking(vector<int>& nums, int startIndex) {
        res.push_back(path);
        if (path.size() == nums.size()) {
            return ;
        }

        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            back_tracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        back_tracking(nums, 0);
        return res;
    }
};
