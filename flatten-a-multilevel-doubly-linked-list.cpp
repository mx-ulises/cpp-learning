/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

struct FlattenSublist {
    Node* head;
    Node* tail;
};

class Solution {
private:
    Node* updateTail(Node* tail, FlattenSublist flattenSublist) {
        if (flattenSublist.head != nullptr) {
            tail->next = flattenSublist.head;
            flattenSublist.head->prev = tail;
            tail = flattenSublist.tail;
        }
        return tail;
    }

    FlattenSublist getFlattenSublist(Node* head) {
        if (head == nullptr) {
            return {nullptr, nullptr};
        }

        FlattenSublist childFlattenSublist = getFlattenSublist(head->child);
        FlattenSublist nextFlattenSublist = getFlattenSublist(head->next);
        head->child = nullptr;

        Node* tail = head;
        tail = updateTail(tail, childFlattenSublist);
        tail = updateTail(tail, nextFlattenSublist);

        return {head, tail};
    }

public:
    Node* flatten(Node* head) {
        return getFlattenSublist(head).head;
    }
};
