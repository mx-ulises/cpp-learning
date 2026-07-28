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

struct MaxPathSumOutput {
    int maxPathIncludingNode;
    int maxPath;
    int childPath;
    bool isValid;
};

class Solution {
private:
    void updateOutput(MaxPathSumOutput& output, TreeNode* parent, TreeNode* child) {
        MaxPathSumOutput childOutput = getMaxPathSum(child);
        if (childOutput.isValid) {
            output.maxPathIncludingNode = max(output.maxPathIncludingNode, parent->val + childOutput.maxPathIncludingNode);
            output.maxPath = max(output.maxPath, childOutput.maxPath);
            output.childPath += childOutput.maxPathIncludingNode;
        }
        output.maxPath = max(output.maxPath, output.childPath);
        output.maxPath = max(output.maxPath, output.maxPathIncludingNode);
    }

    MaxPathSumOutput getMaxPathSum(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0, 0, false};
        }
        MaxPathSumOutput output = {node->val, node->val, node->val, true};
        updateOutput(output, node, node->left);
        updateOutput(output, node, node->right);
        return output;
    }
public:
    int maxPathSum(TreeNode* root) {
        return getMaxPathSum(root).maxPath;
    }
};
