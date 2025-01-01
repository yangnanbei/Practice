class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void back_tracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);
            back_tracking(n, k, i + 1);
            path.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        back_tracking(n, k, 1);
        return res;
    }
};
