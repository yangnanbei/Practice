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
class Solution {
public:
    int minDepth(TreeNode* root) {
        int min_depth = 0;
        int size;
        queue<TreeNode*> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (!cur->left && !cur->right) {
                    return ++min_depth;
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            min_depth++;
        }
        return min_depth;
    }
};
