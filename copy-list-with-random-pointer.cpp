/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    Node* getNewNode(unordered_map<Node*, Node*>& nodeMap, Node* node) {
        if (!nodeMap.contains(node)) {
            nodeMap[node] = new Node(node->val);
        }
        return nodeMap[node];
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> nodeMap;
        nodeMap[nullptr] = nullptr;
        nodeMap[head] = new Node(head->val);
        Node* current = head;
        while (current != nullptr) {
            nodeMap[current]->next = getNewNode(nodeMap, current->next);
            nodeMap[current]->random = getNewNode(nodeMap, current->random);
            current = current->next;
        }
        return nodeMap[head];
    }
};
