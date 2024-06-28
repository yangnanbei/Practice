#include "common.hpp"

/*
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 */

/* 犹豫不决先排序，步步紧逼双指针 */

/*
 * 先将 nums 排序，时间复杂度为 O(NlogN)。
 *
 * 固定 3 个指针中最左（最小）元素的指针 k，双指针 i，j 分设在数组索引 (k,len(nums)) 两端。
 *
 * 双指针 i , j 交替向中间移动，记录对于每个固定指针 k 的所有满足 nums[k] + nums[i] + nums[j] == 0 的 i,j 组合：
 *
 * 当 nums[k] > 0 时直接break跳出：因为 nums[j] >= nums[i] >= nums[k] > 0，即 3 个元素都大于 0 ，在此固定指针 k 之后不可能再找到结果了。
 * 当 k > 0且nums[k] == nums[k - 1]时即跳过此元素nums[k]：因为已经将 nums[k - 1] 的所有组合加入到结果中，本次双指针搜索只会得到重复组合。
 * i，j 分设在数组索引 (k,len(nums)) 两端，当i < j时循环计算s = nums[k] + nums[i] + nums[j]，并按照以下规则执行双指针移动：
 * 当s < 0时，i += 1并跳过所有重复的nums[i]；
 * 当s > 0时，j -= 1并跳过所有重复的nums[j]；
 * 当s == 0时，记录组合[k, i, j]至res，执行i += 1和j -= 1并跳过所有重复的nums[i]和nums[j]，防止记录到重复组合。
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> myVector; // 用于return
        vector<int> temp;             // 用于暂存vector<int>
        if (nums.size() < 3) {
            return myVector;
        }
        sort(nums.begin(), nums.end()); // nums排序
        int i = 0;
        int j = 0;
        int k = 0;
        int s = 0;
        for (k = 0; k < nums.size() - 1; k++) {
            if (nums[k] > 0) {
                break; // 直接跳出
            }
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue; // 继续下一个循环k++
            }
            i = k + 1;           // k的左边
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> myVector; // 用于return
        vector<int> temp;             // 用于暂存vector<int>
        if (nums.size() < 3) {
            return myVector;
        }
        sort(nums.begin(), nums.end()); // nums排序
        int i = 0;
        int j = 0;
        int k = 0;
        int s = 0;
        for (k = 0; k < nums.size() - 1; k++) {
            if (nums[k] > 0) {
                break; // 直接跳出
            }
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue; // 继续下一个循环k++
            }
            i = k + 1;           // k的左边
            j = nums.size() - 1; // 最右边
            while (i < j) {
                s = nums[i] + nums[j] + nums[k]; // 和
                if (s < 0) {
                    i += 1;
                    while (i < j && nums[i] == nums[i - 1]) {
                        i += 1; // i重复，i++
                    }
                } else if (s > 0) {
                    j -= 1;
                    while (i < j && nums[j] == nums[j + 1]) {
                        j -= 1; // j重复,j--
                    }
                } else {
                    temp.clear();
                    temp.push_back(nums[k]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    myVector.push_back(temp);
                    // k不变的情况下有其他的可能性
                    i += 1;
                    j -= 1;
                    // 再次判断有无重复项
                    while (i < j && nums[i] == nums[i - 1]) {
                        i += 1;
                    }
                    while (i < j && nums[j] == nums[j + 1]) {
                        j -= 1;
                    }
                }
            }
        }
        return myVector;
    }
};

int main() {
    Solution s;
    vector<int> test1 = {-1,0,1,2,-1,-4};
    vector<int> res = s.threeSum(test1);
    cout << "res is ";
    for (auto val: res) {
        cout << " " << val;
    }
    cout << endl;

    return 0;
}
