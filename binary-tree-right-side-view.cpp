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
    void fillRightSideView(TreeNode* node, int level, vector<int>& output) {
        if (node == nullptr) return;
        if (level == output.size()) output.push_back(0);
        output[level] = node->val;
        level++;
        fillRightSideView(node->left, level, output);
        fillRightSideView(node->right, level, output);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        fillRightSideView(root, 0, output);
        return output;
    }
};
