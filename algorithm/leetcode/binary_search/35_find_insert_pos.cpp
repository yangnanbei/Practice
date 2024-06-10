#include <bits/stdc++.h>
using namespace std;

/*
35. 搜索插入位置
简单
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2
示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1
示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4

   */


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size();
        int left = 0;
        int middle = (right + left) >> 2;

        while (left < right) {
            // why here
            middle = left + ((right - left) >> 2);
            if (target == nums[middle]) {
                return middle;
            } else if (target < nums[middle]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return right;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << s.searchInsert(nums, target) << endl;
    return 0;
}