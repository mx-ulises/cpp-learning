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
        return (node->left == nullptr) && (node->right == nullptr);
    }

    int getMinDepth(TreeNode* node, int depth) {
        if (node == nullptr) {
            return 100001;
        }
        depth++;
        if (isLeaf(node)) {
            return depth;
        }
        return min(getMinDepth(node->left, depth), getMinDepth(node->right, depth));
    }

public:
    int minDepth(TreeNode* root) {
        return getMinDepth(root, 0);
    }
};
