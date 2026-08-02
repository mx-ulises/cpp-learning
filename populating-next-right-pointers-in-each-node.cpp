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

struct NodeLevelPair {
    Node* node;
    int level;
};

class Solution {
public:
    Node* connect(Node* root) {
        NodeLevelPair prev = {nullptr, -1};
        queue<NodeLevelPair> q;
        q.push({root, 0});
        while (0 < q.size()) {
            NodeLevelPair current = q.front();
            q.pop();
            if (current.node == nullptr) {
                continue;
            }
            if (prev.level == current.level) {
                prev.node->next = current.node;
            }
            prev = current;
            current.level++;
            q.push({current.node->left, current.level});
            q.push({current.node->right, current.level});
        }
        return root;
    }
};
