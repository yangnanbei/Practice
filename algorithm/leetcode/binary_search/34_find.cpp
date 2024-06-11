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

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> findPos(vector<int>& nums, int target) {
		if (!nums.size()) {

		}
		int start = -1;
		int end = -1;
		int left = 0;
		int right = nums.size();
		int middle;
		int find_flag = 0;

		while (left < right) {
			middle = left + ((right - left) >> 1);
			if (target == nums[middle])  {
				find_flag = 1;	
				break;
			} else if (target < nums[middle]) {
				right = middle;
			} esle {
				left = middle + 1;
			}
		}

		if (find_flag) {
			start = end = middle;			
			while(nums[start] == target){
				start--;
			}
			start++;
			while(nums[end] == target){
				end++
			}
			end--;
			return {start, end};
		}
		return {-1,-1};
	}
}
