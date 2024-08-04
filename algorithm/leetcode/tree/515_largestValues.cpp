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
    vector<int> largestValues(TreeNode* root) {
		  if (!root) {
			  return {};
		  }
		  int size;
		  TreeNode* cur;
		  vector<int> res;
		  queue<TreeNode*> que;
		  que.push(root);
		  while (!que.empty()) {
			  size = que.size();
        int largest_level_num = INT_MIN;
			  for (int i = 0; i < size; i++) {
				  cur = que.front();
				  que.pop();
          largest_level_num = largest_level_num > cur->val? largest_level_num: cur->val;
				  if (cur->left) {
					  que.push(cur->left);
				  }
				  if (cur->right) {
					  que.push(cur->right);
				  }
			  }
			  res.push_back(largest_level_num);
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

    std::vector<int> res;
    res = s. largestValues(root);
    //res = s.preorderNorecurTraversal(root);
 
    for (const auto& element : res) {
        std::cout << element << " ";
    }
    std::cout << std::endl; // 每打印完一个内层 vector 后换行

    return 0;
}
