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
        while (head != nullptr) {
            head = head->next;
            n++;
        }
        return n;
    }

    ListNode* getNode(ListNode* head, int i) {
        while (i != 0) {
            head = head->next;
            i--;
        }
        return head;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* succ = nullptr;
        while (node != nullptr) {
            succ = node->next;
            node->next = prev;
            prev = node;
            node = succ;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        int n = getLen(head);
        ListNode* midNode = getNode(head, n /2);
        ListNode* tail = reverse(midNode);
        while (tail != nullptr) {
            if (head->val != tail->val) return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};
