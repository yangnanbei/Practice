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
    void traversal(TreeNode* cur, vector<int>& vec) {
        if (!cur) {
            return ;
        }
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }

	/* no recur version */
    /* 前序遍历是中左右，则入栈的时候用中右左的顺序入栈 */
	vector<int> preorderNorecurTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> res;
        // here need to define TreeNode to iterate the node
        // std::stack<int> st;
        std::stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if (node->right) {
               st.push(node->right);
            }
            if (node->left) {
               st.push(node->left);
            }
        }
        return res;
	}
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::vector<int> res;
    //res = s.preorderTraversal(root);
    res = s.preorderNorecurTraversal(root);
 
    for (int i : res) {
        std::cout << i << " ";
    }
    cout << endl;

    return 0;
}
