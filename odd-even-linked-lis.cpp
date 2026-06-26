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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode();
        ListNode* oddCurrent = oddHead;
        ListNode* evenHead = new ListNode();
        ListNode* evenCurrent = evenHead;
        while (head != nullptr) {
            oddCurrent->next = head;
            oddCurrent = oddCurrent->next;
            head = head->next;
            oddCurrent->next = nullptr;
            if (head != nullptr) {
                evenCurrent->next = head;
                evenCurrent = evenCurrent->next;
                head = head->next;
                evenCurrent->next = nullptr;
            }
        }
        oddCurrent->next = evenHead->next;
        return oddHead->next;
    }
};
