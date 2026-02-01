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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        while (current->next != nullptr) {
            addGCD(current);
            current = current->next->next;
        }
        return head;
    }

private:
    void addGCD(ListNode* current) {
        ListNode* succesor = current->next;
        int gcd = getGCD(current->val, succesor->val);
        current->next = new ListNode{gcd, succesor};
    }

    int getGCD(int a, int b) {
        int r;
        while (b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
};
