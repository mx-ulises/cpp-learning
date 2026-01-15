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
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::vector<TreeNode*> q;
        q.push_back(root);
        int level = 0;
        while (0 < q.size()) {
            if (isOdd(level)) {
                reverseNodeValues(q);
            }
            q = getNextLevel(q);
            level++;
        }
        return root;
    }

    bool isOdd(int x) {
        return (x & 1) == 1;
    }

    void reverseNodeValues(std::vector<TreeNode*> q) {
        int left = 0;
        int right = q.size() - 1;
        while (left < right) {
            int aux = q[left]->val;
            q[left]->val = q[right]->val;
            q[right]->val = aux;
            left++;
            right--;
        }
    }

    std::vector<TreeNode*> getNextLevel(std::vector<TreeNode*> q) {
        std::vector<TreeNode*> r;
        if (!isLastLevel(q)) {
            for (int i = 0; i < q.size(); i++) {
                r.push_back(q[i]->left);
                r.push_back(q[i]->right);
            }
        }
        return r;
    }

    bool isLastLevel(std::vector<TreeNode*> q) {
        return q[0]->left == nullptr;
    }

};
