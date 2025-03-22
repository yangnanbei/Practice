class Solution {
public:
    static inline int getMapNums(char c) {
        return c - 'a';
    }

    vector<int> partitionLabels(string s) {
        // in orders, so get first and last?
        int distance[26] = {};
        char tmp_ch;
        for (int i = 0; i < s.size(); i++) {
            distance[getMapNums(s[i])] = i;
        }

        // impressive! get the longest distance
        int left = 0;
        int right = 0;
        vector<int> res = {};
        for (int i = 0; i < s.size(); i++) {
            right = max(right, distance[getMapNums(s[i])]);
            if (i == right) {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return res;
    }
};
