class Solution {
private:
    const string letterMap[10] = {
        "",     /* 0 */
        "",     /* 1 */
        "abc",  /* 2 */
        "def",  /* 3 */
        "ghi",  /* 4 */
        "jkl",  /* 5 */
        "mno",  /* 6 */
        "pqrs", /* 7 */
        "tuv",  /* 8 */
        "wxyz", /* 9 */
    };
    vector<string> res;
    string path;
public:
    void back_tracking(const string& digits, int index) {
        if (index == digits.size()) {
            res.push_back(path);
            return ;
        }

        int key = digits[index] - '0';
        string letter = letterMap[key];
        for (int i = 0; i < letter.size(); i++) {
            path.push_back(letter[i]);
            back_tracking(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return res;
        }
        back_tracking(digits, 0);
        return res;
    }
};
