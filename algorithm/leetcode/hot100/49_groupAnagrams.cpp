class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        std::unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
 
        for (auto cur_str: strs) {
            std::string tmp_str = cur_str;
            std::sort(tmp_str.begin(), tmp_str.end());
            mp[tmp_str].push_back(cur_str);
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
