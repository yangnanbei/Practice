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
    bool isSymmetric(TreeNode* root) {
      queue<TreeNode*> que;
      if (root) { 
        que.push(root->left);
        que.push(root->right);
      };

      while (!que.empty()) {
        TreeNode* left = que.front();
        que.pop();
        TreeNode* right = que.front();
        que.pop();

        if (!left && !right) {
          continue;
        } else if (!left || !right) {
          return false;
        } else if (left->val != right->val) {
          return false;
        }

        que.push(left->left);
        que.push(right->right);
        que.push(left->right);
        que.push(right->left);
      }
      return true; 
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
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    bool flag;
    flag = s.isSymmetric(root);
    cout << "flag is " << flag << endl;
 
    return 0;
}
