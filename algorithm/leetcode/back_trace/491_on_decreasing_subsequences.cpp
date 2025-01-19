#define MIN_RES_SIZE 2

class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    void back_tracking(vector<int> &nums, int startIndex) {
        if (path.size() >= MIN_RES_SIZE) {
            res.push_back(path);
        }

        if (path.size() == nums.size()) {
            return ;
        }

        unordered_set<int> set;
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || set.find(nums[i]) != set.end()) {
                continue;
            }

            set.insert(nums[i]);
            path.push_back(nums[i]);
            back_tracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        back_tracking(nums, 0);
        return res;
    }
};
