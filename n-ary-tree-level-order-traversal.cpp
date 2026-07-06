/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void addTree(Node* node, vector<vector<int>>& levels, int level) {
        if (node == nullptr) {
            return;
        }
        if (levels.size() == level) {
            levels.push_back(vector<int>());
        }
        levels[level].push_back(node->val);
        level++;
        for (Node* child : node->children) {
            addTree(child, levels, level);
        }
    }

public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        addTree(root, levels, 0);
        return levels;
    }
};
