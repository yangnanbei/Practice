#include <bits/stdc++.h>
using namespace std;
/**
  给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

Attention:
    你需要注意区间是【）还是【】
    我的选择是【），这样符合C语言的习惯

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size();
        int left = 0;
        int middle = (left + right) / 2;
        while (left < right) {
            if (target == nums[middle]) {
                return middle;
            } else if (target < nums[middle]) {
                right = middle;
                middle = (left + right) / 2;
            } else {
                left = middle + 1;
                middle = (left + right) / 2;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << s.search(nums, target) << endl;
    return 0;
}