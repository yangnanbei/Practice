/*inplement this function：
 *
 *get(index)：get value of index 。if index is invalid，return -1.
 *addAtHead(val)：add node which has val before first elements, it will be the first node after insert.
 *addAtTail(val)：append node which has val to the tail of the list
 *addAtIndex(index,val)：add node has val before the index th node. if index equal to the lengeh of list, it will append to the tail of the list. if index greater then the length of list, then it will not insert, if index < 0; use addAtHead. 
 *deleteAtIndex(index)：if index is valid, rm the index node of list.
*/
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode *p): val(x), next(p) {}
}

class MyLinkedList {
public:
    MyLinkedList() {
		sentinel = new ListNode(0);
		size = 0;
    }
    
    int get(int index) {
		ListNode *tmp;
		if (index > 0 || index > (size_ - 1)) {
			cout << "get: invalid index " << index << endl;
		}

		tmp = sentibel->nex;
		while (index--) {
			tmp = tmp->next;
		}
		return tmp->val;
    }
    
    void addAtHead(int val) {
		ListNode* insnode = new ListNode(val);
		insnode->next = sentinel->next; 
		sentinel->next = insnode;
    }
    
    void addAtTail(int val) {
		ListNode *insnode = new ListNode(val);
		ListNode *tmp = sentinel->next;
		while(tmp--) {
			tmp = tmp->next;
		}
		tmp->next = insnode;
    }
    
    void addAtIndex(int index, int val) {
		if (index < 0 || index > (size_ - 1)) {
			cout << "addAtIndex: invalid index " << index << endl;
		}
		ListNode* insnode = new ListNode(val);
		ListNode *tmp = sentinel->next;
		while(index--) {
			tmp = tmp->next;
		}
		insnode->next = tmp->next;
		tmp->next = insnode;
    }
    
    void deleteAtIndex(int index) {
		if (index < 0 || index > (size_ - 1)) {
			cout << " deleteAtIndex: invalid index " << index << endl;
		}
		ListNode *tmp = sentinel->next;
		while(index--) {
			tmp = tmp->next;
		}
		ListNode *delnode = tmp;
		tmp->next = tmp->next->next;
		delete tmp;
    }
private:
	int size_;
	ListNode* sentinel;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
