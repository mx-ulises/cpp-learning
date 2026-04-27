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
    void removeNode(ListNode* fakeHead, ListNode* node) {
        ListNode* prev = fakeHead;
        ListNode* current = fakeHead->next;
        while (current != node) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
    }

    void insertNode(ListNode* fakeHead, ListNode* node, ListNode* limit) {
        ListNode* prev = fakeHead;
        ListNode* current = fakeHead->next;
        while (current != limit && current->val < node->val) {
            prev = current;
            current = current->next;
        }
        prev->next = node;
        node->next = current;
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* fakeHead = new ListNode(-5001, head);
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            removeNode(fakeHead, current);
            insertNode(fakeHead, current, next);
            current = next;
        }
        return fakeHead->next;
    }
};
