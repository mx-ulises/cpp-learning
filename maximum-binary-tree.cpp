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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = constructMaximumBinaryTree(nums, 0, nums.size() - 1);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int left, int right) {
        if (right < left) {
            return nullptr;
        }
        int mid = getMaxElementIndex(nums, left, right);
        TreeNode* node = new TreeNode(
            nums[mid],
            constructMaximumBinaryTree(nums, left, mid - 1),
            constructMaximumBinaryTree(nums, mid + 1, right)
        );
        return node;
    }

    int getMaxElementIndex(vector<int>& nums, int left, int right) {
        int maxElementIndex = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[maxElementIndex] < nums[i]) {
                maxElementIndex = i;
            }
        }
        return maxElementIndex;
    }
};
