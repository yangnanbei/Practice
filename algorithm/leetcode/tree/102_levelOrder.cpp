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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> tmp_res;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                tmp_res.push_back(cur->val);
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res.push_back(tmp_res);
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

    std::vector<vector<int>> res;
    res = s.levelOrder(root);
    //res = s.preorderNorecurTraversal(root);
 
    for (const auto& innerVector : res) {
        for (const auto& element : innerVector) {
            std::cout << element << " ";
        }
        std::cout << std::endl; // 每打印完一个内层 vector 后换行
    }

    return 0;
}
