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
    ListNode* updatePrev(ListNode* prev, ListNode* current) {
        if (prev->val != current->val) {
            prev = current;
        } else {
            prev->next = current->next;
        }
        return prev;
    }

public:
    ListNode* deleteDuplicates(ListNode* current) {
        ListNode* mockHead = new ListNode(-101, current);
        ListNode* prev = mockHead;
        while (current != nullptr) {
            prev = updatePrev(prev, current);
            current = current->next;
        }
        return mockHead->next;
    }
};
