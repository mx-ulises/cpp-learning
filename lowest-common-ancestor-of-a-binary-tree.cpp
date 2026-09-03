/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    bool getList(TreeNode* node, TreeNode* target, vector<TreeNode*>& list) {
        if (node == nullptr) return false;
        list.push_back(node);
        if (node == target) return true;
        if (getList(node->left, target, list)) return true;
        if (getList(node->right, target, list)) return true;
        list.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pList;
        getList(root, p, pList);
        vector<TreeNode*> qList;
        getList(root, q, qList);
        int i = 0;
        TreeNode* lca = nullptr;
        while (i < min(pList.size(), qList.size())) {
            if (pList[i] != qList[i]) break;
            lca = pList[i];
            i++;
        }
        return lca;
    }
};
