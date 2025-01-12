class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
public:
    bool isPalindrome(const string &s) {
        int start = 0;
        int end = s.length();
        for (int i = start, j = end - 1; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backTracking(const string &s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return ;
        }

        for (int i = startIndex; i < s.size(); i++) {
            string str = s.substr(startIndex, i - startIndex + 1);
            if (isPalindrome(str)) {
                path.push_back(str);
            } else {
                continue ;
            }

            backTracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return res;
    }
};
