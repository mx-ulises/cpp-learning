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
    int countElements(ListNode* head) {
        int elementCount = 0;
        while(head != nullptr) {
            head = head->next;
            elementCount++;
        }
        return elementCount;
    }

    int updateListSize(int listSize, int listWithExtraElements) {
        if (0 < listWithExtraElements) {
            listSize++;
        }
        return listSize;
    }

    ListNode* getListTail(ListNode* head, int listSize) {
        ListNode* tail = nullptr;
        while (listSize--) {
            tail = head;
            head = head->next;
        }
        return tail;
    }

    ListNode* cutTail(ListNode* tail) {
        ListNode* aux = nullptr;
        if (tail != nullptr) {
            aux = tail->next;
            tail->next = nullptr;
        }
        return aux;
    }

    ListNode* splitList(ListNode* head, int listSize, int listWithExtraElements) {
        listSize = updateListSize(listSize, listWithExtraElements);
        ListNode* tail = getListTail(head, listSize);
        return cutTail(tail);        
    }

public:
    vector<ListNode*> splitListToParts(ListNode* head, int listCount) {
        vector<ListNode*> output(listCount);
        int elementCount = countElements(head);
        int listSize = elementCount / listCount;
        int listWithExtraElements = elementCount % listCount;
        for(int i = 0; i < listCount; i++) {
            output[i] = head;
            head = splitList(head, listSize, listWithExtraElements--);
        }
        return output;
    }
};
