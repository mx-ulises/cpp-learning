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
    bool isLesser(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return false;
        return list2 == nullptr || list1->val < list2->val;
    }

    ListNode* updateCurrentAndMoveList(ListNode* current, ListNode* list) {
        current->next = list;
        return list->next;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* fakeHead = new ListNode();
        ListNode* current = fakeHead;
        while (list1 != nullptr || list2 != nullptr) {
            if (isLesser(list1, list2)) {
                list1 = updateCurrentAndMoveList(current, list1);
            } else {
                list2 = updateCurrentAndMoveList(current, list2);
            }
            current = current->next;
        }
        return fakeHead->next;
    }
};
