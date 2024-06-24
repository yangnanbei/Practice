#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (!nums.size()) {
            return {};
        }
        std::unordered_map<int, int>  umap;
        int target_num;
        for (int i = 0; i < nums.size(); i++) {
            target_num = target - nums[i];
            if (umap.count(target_num)) {
                return {umap[target_num], i};
            }
            umap.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main() {
    Solution solution;
    // 输入
    vector<int> nums = {2, 7, 11, 15, 3, 5};
    int target = 8;

    // 输出
    vector<int> result = solution.twoSum(nums, target);

    // 打印结果
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}