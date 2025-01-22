class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void back_track(vector<int> &nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return ;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) {
                continue;
            }

            used[i] = true;
            path.push_back(nums[i]);
            back_track(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        back_track(nums, used);
        return res;
    }
};
