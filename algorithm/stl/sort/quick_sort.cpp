#include <iostream>
#include <vector>
using namespace std;

/* 
基本思想：
采用“分治”的思想，对于一组数据，选择一个基准元素（base），通常选择第一个或最后一个元素，通过第一轮扫描，比base小的元素都在base左边，比base大的元素都在base右边，再有同样的方法递归排序这两部分，直到序列中所有数据均有序为止。
*/

class Solution {
public:
    void quickSort(vector<int>& nums, int start, int end) {
        if (!nums.size() || nums.size() == 1) {
            return ;
        }
        if (start > end) {
            return ;
        }
        int base = nums[start];
        int left = start;
        int right = end;
        while (left < right) {
            while (left < right && nums[right] >= base) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= base) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = base;
        quickSort(nums, start, left - 1);
        quickSort(nums, left + 1, end);
    }
};

int main() {
    Solution s;
    vector<int> vec = {324,6,7,23,1,67,44,323};
    cout << "val is ";
    for (auto val:vec) {
        cout << " " << val;
    }
    cout << endl;

    s.quickSort(vec, 0, vec.size() - 1);

    cout << "after sort val is :" << endl;
    cout << "val is ";
    for (auto val:vec) {
        cout << " " << val;
    }
    cout << endl;
    return 0;
}