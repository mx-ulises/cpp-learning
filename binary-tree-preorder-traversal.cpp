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
    void processTopNode(stack<TreeNode*>& s, vector<int>& output) {
        TreeNode* node = s.top();
        s.pop();
        if (node != nullptr) {
            output.push_back(node->val);
            s.push(node->right);
            s.push(node->left);
        }
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode*> s({root});
        while(!s.empty()) {
            processTopNode(s, output);
        } 
        return output;
    }
};
