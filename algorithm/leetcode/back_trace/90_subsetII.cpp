class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void back_tracking(vector<int>& nums, int startIndex) {
        res.push_back(path);
        if (startIndex == nums.size()) {
            return ;
        }

        unordered_set<int> set;
        for (int i = startIndex; i < nums.size(); i++) {
            if (set.find(nums[i]) != set.end()) {
                continue;
            }

            set.insert(nums[i]);
            path.push_back(nums[i]);
            back_tracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        back_tracking(nums, 0);
        return res;
    }
};
