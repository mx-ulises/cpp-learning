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
    TreeNode* insertNode(int val, unordered_map<int, TreeNode*>& nodes) {
        nodes.insert({val, new TreeNode(val)});
        return nodes[val];
    }

    void connectChildWithParent(TreeNode* parent, TreeNode* child, bool isLeft, unordered_set<int>& hasParent) {
        hasParent.insert(child->val);
        if (isLeft) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> hasParent;
        for (auto& description : descriptions) {
            TreeNode* parent = insertNode(description[0], nodes);
            TreeNode* child = insertNode(description[1], nodes);
            connectChildWithParent(parent, child, description[2], hasParent);
        }
        for (auto& description : descriptions) {
            int parentVal = description[0];
            if (hasParent.find(parentVal) == hasParent.end()) {
                return nodes[parentVal];
            }
        }
        return nullptr;
    }
};
