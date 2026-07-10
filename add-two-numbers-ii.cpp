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
    void fillStack(ListNode* l, stack<int>& s) {
        while (l != nullptr) {
            s.push(l->val);
            l = l->next;
        }
    }

    int getAndPop(stack<int>& s) {
        int val = 0;
        if (0 < s.size()) {
            val = s.top();
            s.pop();
        }
        return val;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        fillStack(l1, s1);
        fillStack(l2, s2);
        int carry = 0;
        ListNode* head = nullptr;
        while (0 < s1.size() || s2.size() || 0 < carry) {
            carry += getAndPop(s1) + getAndPop(s2);
            ListNode* pred = new ListNode(carry % 10, head);
            head = pred;
            carry /= 10;
        }
        return head;
    }
};
