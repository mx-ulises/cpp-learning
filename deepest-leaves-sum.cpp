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

 #include <unordered_map>
 #include <algorithm>
 
 class Solution {
 public:
     int deepestLeavesSum(TreeNode* root) {
         int depestLevel = getDeepestLevel(root, 0);
         return getDeepestLeavesSum(root, depestLevel);
     }
 
     int getDeepestLevel(TreeNode* node, int currentLevel) {
         if (node == nullptr) {
             return currentLevel - 1;
         }
         currentLevel++;
         int leftDeepestLevel = getDeepestLevel(node->left, currentLevel);
         int rightDeepestLevel = getDeepestLevel(node->right, currentLevel);
         return std::max(leftDeepestLevel, rightDeepestLevel);
     }
 
     int getDeepestLeavesSum(TreeNode* node, int depestLevel) {
         if (node == nullptr) {
             return 0;
         }
         if (depestLevel == 0) {
             return node->val;
         }
         depestLevel--;
         int leftLevelSum = getDeepestLeavesSum(node->left, depestLevel);
         int rightLevelSum = getDeepestLeavesSum(node->right, depestLevel);
         return leftLevelSum + rightLevelSum;
     }
 };
 