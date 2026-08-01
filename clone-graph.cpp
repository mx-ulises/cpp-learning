/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void mapNodes(unordered_map<Node*, Node*>& nodeMap, Node* root) {
        stack<Node*> s;
        s.push(root);
        while (0 < s.size()) {
            Node* node = s.top();
            s.pop();
            if (nodeMap.contains(node)) {
                continue;
            }
            nodeMap[node] = new Node(node->val);
            for (auto& neighboor : node->neighbors) {
                s.push(neighboor);
            }
        }
    }

    void addNeighboors(unordered_map<Node*, Node*>& nodeMap, Node* original, Node* copy) {
        for (auto& neighboor : original->neighbors) {
            copy->neighbors.push_back(nodeMap[neighboor]);
        }
    }

    void connectNodes(unordered_map<Node*, Node*>& nodeMap) {
        for (auto& [original, copy] : nodeMap) {
            addNeighboors(nodeMap, original, copy);
        }
    }

public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> nodeMap;
        mapNodes(nodeMap, node);
        connectNodes(nodeMap);
        return nodeMap[node];
    }
};
