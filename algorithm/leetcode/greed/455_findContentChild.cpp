class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1; 
        int result = 0;
        /* s should be greater than g */
        for (int i = g.size() - 1; i >= 0; i--) { 
            if (index >= 0 && s[index] >= g[i]) { 
                result++;
                index--;
            }
        }
        return result;
    }
};
