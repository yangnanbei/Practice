class Solution {
public:
    static bool cmp(const vector<int>& lhs, const vector<int>& rhs) {
        return lhs[0] < rhs[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        int res = 1;
        sort(points.begin(), points.end(), cmp);

        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {
                res += 1;
            } else {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        
        return res;
    }
};
