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
public:
    ListNode* mergeNodes(ListNode* head) {
        head = mergeListNodes(head);
        head = removeLastNode(head);
        return head;
    }

    ListNode* mergeListNodes(ListNode* head) {
        ListNode* currentMerge = head;
        ListNode* current = currentMerge->next;
        while (current != nullptr) {
            currentMerge = updateCurrentMerge(currentMerge, current);
            current = current->next;
        }
        return head;
    }

    ListNode* updateCurrentMerge(ListNode* currentMerge, ListNode* current) {
        currentMerge->val += current->val;
        if (current->val == 0) {
            currentMerge->next = current;
            currentMerge = current;
        }
        return currentMerge;
    }

    ListNode* removeLastNode(ListNode* head) {
        ListNode* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        current->next = nullptr;
        return head;
    }
};
