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
    void addCombinations(vector<TreeNode*>& level, const vector<TreeNode*>& leftNodes, const vector<TreeNode*>& rightNodes) {
        for (auto leftNode : leftNodes) {
            for (auto rightNode : rightNodes) {
                level.push_back(new TreeNode(0, leftNode, rightNode));
            }
        }
    }

    void fillLevel(map<int, vector<TreeNode*>>& levels, int n) {
        levels[n] = vector<TreeNode*>();
        for (int left = 1; left < n; left += 2) {
            int right = n - left - 1;
            addCombinations(levels[n], levels[left], levels[right]);
        }
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        map<int, vector<TreeNode*>> levels;
        levels[1] = vector<TreeNode*>({new TreeNode()});
        for (int i = 3; i <= n; i += 2) {
            fillLevel(levels, i);
        }
        return levels[n];
    }
};
