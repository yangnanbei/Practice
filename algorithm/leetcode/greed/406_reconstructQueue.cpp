class Solution {
public:
    static bool cmp(const vector<int>& lhs, const vector<int>& rhs) {
        if (lhs[0] == rhs[0]) 
            return (lhs[1] < rhs[1]);

        return (lhs[0] > rhs[0]);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int pos;
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        
        for (int i = 0; i < people.size(); i++) {
            pos = people[i][1];
            que.insert(que.begin() + pos, people[i]);
        }

        return que;
    }
};
