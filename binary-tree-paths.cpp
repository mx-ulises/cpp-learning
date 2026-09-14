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

    void addPath(vector<string>& output, vector<TreeNode*>& currentPath) {
        string path = to_string(currentPath[0]->val);
        for (int i = 1; i < currentPath.size(); i++) {
            path += "->" + to_string(currentPath[i]->val);
        }
        output.push_back(path);
    }

    void fillPaths(TreeNode* node, vector<string>& output, vector<TreeNode*>& currentPath) {
        if (node == nullptr) {
            return;
        }
        currentPath.push_back(node);
        if (isLeaf(node)) {
            addPath(output, currentPath);
        } else {
            fillPaths(node->left, output, currentPath);
            fillPaths(node->right, output, currentPath);
        }
        currentPath.pop_back();
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        vector<TreeNode*> currentPath;
        fillPaths(root, output, currentPath);
        return output;
    }
};
