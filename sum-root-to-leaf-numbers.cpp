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
        return node != nullptr && node->left == nullptr && node->right == nullptr;
    }

    int getSumNumbers(TreeNode* node, int currentSum, int currentTotal) {
        if (node == nullptr) {
            return currentTotal;
        }
        currentSum = currentSum * 10 + node->val;
        if (isLeaf(node)) {
            return currentSum + currentTotal;
        }
        currentTotal = getSumNumbers(node->left, currentSum, currentTotal);
        currentTotal = getSumNumbers(node->right, currentSum, currentTotal);
        return currentTotal;
    }

public:
    int sumNumbers(TreeNode* root) {
        return getSumNumbers(root, 0, 0);
    }

};
