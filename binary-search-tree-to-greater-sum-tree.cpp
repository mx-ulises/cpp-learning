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
private:
    int sumAndUpdate(TreeNode* node, int currentSum) {
        if (node == nullptr) {
            return currentSum;
        }
        node->val += sumAndUpdate(node->right, currentSum);
        return sumAndUpdate(node->left, node->val);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        sumAndUpdate(root, 0);
        return root;
    }
};
