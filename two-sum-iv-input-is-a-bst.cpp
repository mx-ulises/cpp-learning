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
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> visited;
        queue<TreeNode*> q;
        q.push(root);
        while (0 < q.size()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                continue;
            }
            if (visited.find(k - node->val) != visited.end()) {
                return true;
            }
            visited.insert(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        return false;
    }
};
