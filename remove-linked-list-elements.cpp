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
    ListNode* updatePred(ListNode* pred, ListNode* current, int val) {
        if (current->val == val) {
            pred->next = current->next;
        } else {
            pred = current;
        }
        return pred;
    }

public:
    ListNode* removeElements(ListNode* current, int val) {
        ListNode* fakeHead = new ListNode(-1, current);
        ListNode* pred = fakeHead;
        while(current != nullptr) {
            pred = updatePred(pred, current, val);
            current = current->next;
        }
        return fakeHead->next;
    }
};
