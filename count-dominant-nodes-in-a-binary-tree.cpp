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

struct DominantCountAndMaximal{
    int dominantCount;
    int maximal;
};

class Solution {
private:
    DominantCountAndMaximal getDominantCountAndMaximal(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }
        DominantCountAndMaximal leftDCAM = getDominantCountAndMaximal(node->left);
        DominantCountAndMaximal rightDCAM = getDominantCountAndMaximal(node->right);
        int maximal = max(leftDCAM.maximal, rightDCAM.maximal);
        int dominantCount = leftDCAM.dominantCount + rightDCAM.dominantCount;
        if (maximal <= node->val) {
            maximal = node->val;
            dominantCount++;
        }
        return {dominantCount, maximal};
    }

public:
    int countDominantNodes(TreeNode* root) {
        DominantCountAndMaximal dominantCountAndMaximal = getDominantCountAndMaximal(root);
        return dominantCountAndMaximal.dominantCount;
    }
};
