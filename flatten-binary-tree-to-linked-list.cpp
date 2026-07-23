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

struct TreeNodePair {
    TreeNode *head;
    TreeNode *tail;
};

class Solution {
private:
    TreeNode* concatListAndUpdateTail(TreeNode* tail, TreeNode* node) {
        TreeNodePair list = flattenTree(node);
        if (list.head != nullptr) {
            tail->right = list.head;
            tail = list.tail;
        }
        return tail;
    }

    TreeNodePair flattenTree(TreeNode* node) {
        if (node == nullptr) {
            return {nullptr, nullptr};
        }
        TreeNode* head = node, tail = node;
        TreeNode* left = node->left, right = node->right;
        tail = concatListAndUpdateTail(tail, left);
        tail = concatListAndUpdateTail(tail, right);
        node->left = nullptr;
        return {head, tail};
    }

public:
    void flatten(TreeNode* root) {
        flattenTree(root);
    }
};
