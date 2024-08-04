#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      if (!root) {
          return {};
      }
      vector<vector<int>> res;
      queue<Node*> q;
      q.push(root);
      
      while (!q.empty()) {
          int size = q.size();
          vector<int> level;
          for (int i = 0; i < size; ++i) {
              Node* node = q.front();
              q.pop();
              level.push_back(node->val);
              for (Node* child : node->children) {
                  q.push(child);
              }
          }
          res.push_back(level);
      }
      return res;
    }
};


int main() {
    Solution s;
    // 创建节点
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    // 构建树结构
    node1->children = {node2, node3, node4};
    node2->children = {node5, node6};

    // 打印树结构
    cout << "Node 1: " << node1->val << ", Children: ";
    for (Node* child : node1->children) {
        cout << child->val << " ";
    }
    cout << endl;

    cout << "Node 2: " << node2->val << ", Children: ";
    for (Node* child : node2->children) {
        cout << child->val << " ";
    }
    cout << endl;

    std::vector<vector<int>> res;
    res.clear();
    res = s.levelOrder(node1);
    //res = s.preorderNorecurTraversal(root);
 
    if (!res.empty()) {
        for (const auto& innerVector : res) {
            for (const auto& element : innerVector) {
                std::cout << element << " ";
            }
            std::cout << std::endl; // 每打印完一个内层 vector 后换行
        }
    }

    // 释放内存
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    return 0;
}
