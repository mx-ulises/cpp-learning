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
    bool isCycle(ListNode *fast, ListNode *slow) {
        return fast == slow;
    }

    bool isNull(ListNode *fast) {
        return fast == nullptr || fast->next == nullptr;
    }

public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (!isNull(fast) && !isCycle(fast, slow)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return fast == slow;
    }
};
