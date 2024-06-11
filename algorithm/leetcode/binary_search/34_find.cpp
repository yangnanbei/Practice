/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：你可以设计并实现时间复杂度为 $O(\log n)$ 的算法解决此问题吗？

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
*/

/**
	Think: 一共有三种情况：
	1. target在数组范围的左边或者右边，返回{-1, -1}
	2. target在数组范围的中间，但是没有命中，返回{-1, -1}
	3. target在数组范围的中间，并且命中，返回{start, end}
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int leftboard = getLeftBoard(nums, target);
		int rightboard = getRightBoard(nums. target);
	}
private:
	int getLeftBoard(vector<int>& nums, int target) {
		int left = 0, right = nums.size();
		int middle;	
		int left_border = -1;
		while(left < right) {
			middle = left + ((right - left) >> 1);
			if (target >= nums[middle]) {
				right = middle - 1;
				left_border = right;
			} else {
				left = middle + 1;
			}
		}
		return left_border;
	}
};

int main() {
	vector<int> nums = {2,2};
	int target = 2;
	Solution s;
	vector<int> res = s.findPos(nums, target);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}