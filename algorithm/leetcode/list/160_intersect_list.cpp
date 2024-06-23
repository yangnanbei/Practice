#include <list_template.hpp>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return nullptr;
        }
        ListNode* list1 = headA;
        ListNode* list2 = headB;
        int list1_len = 0;
        int list2_len = 0;
        int diff = 0;

        while (list1) {
            list1 = list1->next;
            list1_len++;
        }

        while (list2) {
            list2 = list2->next;
            list2_len++;
        }

        if (list1_len > list2_len) {
            diff = list1_len - list2_len;
            list1 = headA;
            list2 = headB;
        } else {
            diff = - (list1_len - list2_len);
            list1 = headB;
            list2 = headA;
        }

        while (diff--) {
            list1 = list1->next;
        }

        while (list1 && list2) {
            if (list1 == list2) {
                return list1;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
        return nullptr;
    }
};

int main() {

}