#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
      if (!root) {
        return nullptr;
      }
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        Node* prev_node;
        for (int i = 0; i < size; i++) {
          Node* cur = q.front();
          q.pop();
          if (i == 0) {
            prev_node = cur;
          } else {
            prev_node->next = cur;
            prev_node = cur;
          }
          if (cur->left) q.push(cur->left);
          if (cur->right) q.push(cur->right);
        }
        prev_node->next = nullptr;
      }
      return root;
    }
};


int main() {
    Solution s;
    /*
              1
            /   \
          2       3
        /   \   /   \
       4     5  6    7
    */
        // 创建7个节点
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    // 构建二叉树
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    // 打印树的结构（示例）
    std::cout << "Tree structure:" << std::endl;
    std::cout << "1 (root)" << std::endl;
    std::cout << "2 (left of 1)" << std::endl;
    std::cout << "3 (right of 1)" << std::endl;
    std::cout << "4 (left of 2)" << std::endl;
    std::cout << "5 (right of 2)" << std::endl;
    std::cout << "6 (left of 3)" << std::endl;
    std::cout << "7 (right of 3)" << std::endl;

    // 释放内存（示例）
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;


    //Node* res;
    //res = s.connect(root);
 
    return 0;
}
