#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode* ptr): val(val), next(ptr) {}
};

class Solution {
public:
    /* from 1 2 3 4 5 
       to 5 4 3 2 1 */
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp = nullptr;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;

    }

};

int main() {
    // 对 reverseList生成测试代码
    
    // 生成测试数据
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 调用reverseList函数
    ListNode* reversedHead = Solution().reverseList(head);

    // 输出结果
    ListNode* cur = reversedHead; 

    std::cout << "val is " ;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << '\n';

    return 0;
}