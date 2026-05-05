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
    int getLen(ListNode* head) {
        int n = 0;
        while(head != nullptr) {
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode* getTail(ListNode* head) {
        while (head->next != nullptr) {
            head = head->next;
        }
        return head;
    }

    ListNode* getNode(ListNode* head, int n) {
        while (n != 0) {
            head = head->next;
            n--;
        }
        return head;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        int n = getLen(head);
        k %= n;
        if (k == 0) {
            return head;
        }
        ListNode* tail = getTail(head);
        ListNode* newTail = getNode(head, n - k - 1);
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        return newHead;
    }
};
