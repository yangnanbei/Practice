class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    int getSum(vector<int> vec) {
        int sum = 0;
        for (auto val:vec) {
            sum += val;
        }
        return sum;
    }

    void back_tracking(int k, int n, int startIndex) {
        if (path.size() == k && getSum(path) == n) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i < n + 1; i++) {
            path.push_back(i);
            back_tracking(k, n, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        back_tracking(k, n, 1);
        return res;
    }
};
