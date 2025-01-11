class Solution {
private:
int sum;
vector<vector<int>> res;
vector<int> path;
public:
    void back_tracking(vector<int>& candidates, int target, int index) {
        if (sum == target) {
            res.push_back(path);
            return ;
        }

        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            back_tracking(candidates, target, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        back_tracking(candidates, target, 0);
        return res;
    }
};
