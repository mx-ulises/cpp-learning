/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    void connectNodes(Node* node, vector<Node*>& succesors, int level) {
        if (node == nullptr) {
            return;
        }
        if (level == succesors.size()) {
            succesors.push_back(nullptr);
        }
        node->next = succesors[level];
        succesors[level] = node;
        level++;
        connectNodes(node->right, succesors, level);
        connectNodes(node->left, succesors, level);
    }

public:
    Node* connect(Node* root) {
        vector<Node*> succesors;
        connectNodes(root, succesors, 0);
        return root;
    }
};
