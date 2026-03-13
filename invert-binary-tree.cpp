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
    void swapChildren(TreeNode* node) {
        auto aux = invertTree(node->left);
        node->left = invertTree(node->right);
        node->right = aux;
    }
public:
    TreeNode* invertTree(TreeNode* node) {
        if (node != nullptr) {
            swapChildren(node);
        }
        return node;
    }
};
