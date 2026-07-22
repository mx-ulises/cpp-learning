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
    bool isLeaf(TreeNode* node) {
        return node->right == nullptr && node->left == nullptr;
    }

public:
    bool hasPathSum(TreeNode* node, int targetSum) {
        if (node == nullptr) {
            return false;
        }
        targetSum -= node->val;
        if (isLeaf(node)) {
            return targetSum == 0;
        }
        return hasPathSum(node->left, targetSum) || hasPathSum(node->right, targetSum);
    }
};
