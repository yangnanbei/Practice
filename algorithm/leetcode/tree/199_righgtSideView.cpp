#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 /* we need to handle the recur and no-recur version */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
      if (!root) {
        return {};
      }
      queue<TreeNode*> que;
      que.push(root);
      vector<int> res;
      while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
          TreeNode* node = que.front();
          que.pop();
          if (i == size - 1) {
            res.push_back(node->val);
          }
          if (node->left) que.push(node->left);
          if (node->right) que.push(node->right);
        }
      }
      return res;
    }
};


int main() {
    Solution s;
    /*
              1
            /   \
          2       3
        /   \
       4     5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::vector<int> res;
    res = s.rightSideView(root);
    //res = s.preorderNorecurTraversal(root);
 
    for (const auto& element : res) {
        std::cout << element << " ";
    }
    std::cout << std::endl; // 每打印完一个内层 vector 后换行

    return 0;
}
