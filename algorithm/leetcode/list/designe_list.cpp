/*inplement this function：
 *
 *get(index)：get value of index 。if index is invalid，return -1.
 *addAtHead(val)：add node which has val before first elements, it will be the first node after insert.
 *addAtTail(val)：append node which has val to the tail of the list
 *addAtIndex(index,val)：add node has val before the index th node. if index equal to the lengeh of list, it will append to the tail of the list. if index greater then the length of list, then it will not insert, if index < 0; use addAtHead. 
 *deleteAtIndex(index)：if index is valid, rm the index node of list.
*/

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

    }
    
    int get(int index) {

    }
    
    void addAtHead(int val) {

    }
    
    void addAtTail(int val) {

    }
    
    void addAtIndex(int index, int val) {

    }
    
    void deleteAtIndex(int index) {

    }
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