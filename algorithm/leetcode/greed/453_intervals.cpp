class Solution {
public:
    static bool cmp(const vector<int>& lhs, const vector<int>& rhs) {
        return (lhs[0] < rhs[0]);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 1;
        sort(intervals.begin(), intervals.end(), cmp);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= intervals[i - 1][1]) {
                res += 1;
            } else {
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
            }
        }

        return intervals.size() - res;   
    }
};
