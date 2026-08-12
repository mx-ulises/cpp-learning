/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
private:
    int getSize(ListNode *head) {
        int n = 0;
        while(head != nullptr) {
            head = head->next;
            n++;
        }
        return n;
    }

    ListNode *move(ListNode* head, int n) {
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
        return head;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = getSize(headA);
        int m = getSize(headB);
        int diff = abs(n - m);
        if (n < m) {
            headB = move(headB, diff);
        } else {
            headA = move(headA, diff);
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
