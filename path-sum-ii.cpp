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
        return node->left == nullptr && node->right == nullptr;
    }

    void addPaths(TreeNode* node, vector<vector<int>>& output, vector<int>& currentPath, int targetSum) {
        if (node == nullptr) return;
        currentPath.push_back(node->val);
        targetSum -= node->val;
        if (isLeaf(node) && targetSum == 0) {
            output.push_back(currentPath);
        }
        addPaths(node->left, output, currentPath, targetSum);
        addPaths(node->right, output, currentPath, targetSum);
        currentPath.pop_back();
    }

public:

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> output;
        vector<int> currentPath;
        addPaths(root, output, currentPath, targetSum);
        return output;
    }

};
