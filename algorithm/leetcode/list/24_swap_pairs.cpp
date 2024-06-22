#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

/*
输入：head = [1,2,3,4]
输出：[2,1,4,3]
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode *cur = sentinel;

        ListNode *tmp_first = nullptr;
        ListNode *tmp_second = nullptr;
        while (cur->next && cur->next->next) {
            tmp_first = cur->next;
            tmp_second = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = tmp_first;
            cur->next->next->next = tmp_second;

            cur = cur->next->next;
        }
        head = sentinel->next;
        delete sentinel;
        return head;
    }
};

int main() {
    // 请针对swapPairs构建测试 并打印结果

    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    ListNode* res = s.swapPairs(head);
    while(res) {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;


}

