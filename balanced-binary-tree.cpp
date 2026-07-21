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
    bool isBalanced(int leftHeight, int rightHeight) {
        if (leftHeight == -1) return false;
        if (rightHeight == -1) return false;
        return abs(leftHeight - rightHeight) <= 1;
    }

    int getHeightIfBalanced(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = getHeightIfBalanced(node->left);
        int rightHeight = getHeightIfBalanced(node->right);
        if (isBalanced(leftHeight, rightHeight) == false) {
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        return getHeightIfBalanced(root) != -1;
    }
};
