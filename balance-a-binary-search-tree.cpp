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
    void getAllNodesInOrder(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node == nullptr)
            return;
        getAllNodesInOrder(node->left, nodes);
        nodes.push_back(node);
        getAllNodesInOrder(node->right, nodes);
    }

    TreeNode* buildBalancedTree(vector<TreeNode*>& nodes, int left, int right) {
        if (right < left)
            return nullptr;
        int mid = (left + right) / 2;
        nodes[mid]->left = buildBalancedTree(nodes, left, mid - 1);
        nodes[mid]->right = buildBalancedTree(nodes, mid + 1, right);
        return nodes[mid];
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes(0);
        getAllNodesInOrder(root, nodes);
        return buildBalancedTree(nodes, 0, nodes.size() - 1);
    }
};
