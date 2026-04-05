/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* getTail(ListNode* head) {
        while(head != nullptr && head->next != nullptr) {
            head = head->next;
        }
        return head;
    }

    void reverseNode(ListNode* node, ListNode* prev) {
        if (node == nullptr) return;
        reverseNode(node->next, node);
        node->next = prev;
    }

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tail = getTail(head);
        reverseNode(head, nullptr);
        return tail;
    }
};
