#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* node): val(x), next(node) {}
};

class Solution {
public:
    ListNode* rmElementsFromList(ListNode* head, int target) {
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode* cur = sentinel;

        while (cur->next != NULL) {
            if (cur->next->val == target) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = sentinel->next;
        delete sentinel;
        return head;
    }
};

int main() {
    int target = 4;
    Solution s;  
    ListNode* test_node = new ListNode(0);
    test_node->next = new ListNode(1);
    test_node->next->next = new ListNode(2);
    test_node->next->next->next= new ListNode(3);
    test_node->next->next->next->next = new ListNode(4);
    std::cout << "before rm target elem" << std::endl;
    ListNode *cur = test_node;
    while (cur) {
        cout << "cur val is " << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    s.rmElementsFromList(test_node, target);

    std::cout << "after rm target elem" << std::endl;
    cur = test_node;
    while (cur) {
        cout << "cur val is " << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    delete cur;
    return 0;
}