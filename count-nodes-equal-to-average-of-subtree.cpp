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

struct SubtreeTraverseOutput {
    int nodeSum;
    int nodeCount;
    int validNodeCount;
};

class Solution {
private:
    SubtreeTraverseOutput traverse(TreeNode* node) {
        if (node == nullptr) {
            return {};
        }
        SubtreeTraverseOutput leftOutput = traverse(node->left);
        SubtreeTraverseOutput rightOutput = traverse(node->right);
        SubtreeTraverseOutput output = {
            nodeSum: leftOutput.nodeSum + rightOutput.nodeSum + node->val,
            nodeCount: leftOutput.nodeCount + rightOutput.nodeCount + 1,
            validNodeCount: leftOutput.validNodeCount + rightOutput.validNodeCount
        };
        if ((output.nodeSum / output.nodeCount) == node->val) {
            output.validNodeCount++;
        }
        return output;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        SubtreeTraverseOutput output = traverse(root);
        return output.validNodeCount;
    }
};
