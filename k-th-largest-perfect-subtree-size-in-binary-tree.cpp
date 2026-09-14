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
    int getKthLargestPerfectSubtree(TreeNode* node, int k, priority_queue<int, vector<int>, greater<int>>& minheap) {
        if (node == nullptr) {
            return 0;
        }
        int leftPerfetSize = getKthLargestPerfectSubtree(node->left, k, minheap);
        int rightPerfectSize = getKthLargestPerfectSubtree(node->right, k, minheap);
        if (0 <= leftPerfetSize && leftPerfetSize == rightPerfectSize) {
            int perfectSize = leftPerfetSize + rightPerfectSize + 1;
            minheap.push(perfectSize);
            if (k < minheap.size()) {
                minheap.pop();
            }
            return perfectSize;
        }
        return - 1;
    }

public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        getKthLargestPerfectSubtree(root, k, minheap);
        if (minheap.size() < k) return -1;
        return minheap.top();
    }
};
