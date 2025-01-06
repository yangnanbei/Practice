class Solution {
private:
int sum;
vector<vector<int>> res;
vector<int> path;
public:
    void back_tracking(vector<int>& candidates, int target, int index) {
        if (sum > target) {
            return ;
        }
        if (sum == target) {
            res.push_back(path);
            return ;
        }

        for (int i = index; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            back_tracking(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        back_tracking(candidates, target, 0);
        return res;
    }
};
