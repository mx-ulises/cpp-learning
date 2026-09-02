/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNodePair {
    TreeNode* low;
    TreeNode* high;
};

class Solution {
private:
    TreeNodePair orderNodePair(TreeNode* p, TreeNode* q) {
        if (p->val < q->val) return {p, q};
        return {q, p};
    }

    TreeNode* getLowestCommonAncestor(TreeNode* root, TreeNode* low, TreeNode* high) {
        while (root != nullptr) {
            if (root->val < low->val) root = root->right;
            else if (high->val < root->val) root = root->left;
            else return root;
        }
        return nullptr;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNodePair nodePair = orderNodePair(p, q);
        return getLowestCommonAncestor(root, nodePair.low, nodePair.high);
    }
};
