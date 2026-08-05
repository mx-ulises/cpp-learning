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
    void fillNodes(vector<ListNode*>& nodes, ListNode* node) {
        while (node != nullptr) {
            nodes.push_back(node);
            node = node->next;
        }
    }

    ListNode* updateCurrent(ListNode* current, ListNode* succesor) {
        current->next = succesor;
        return succesor;
    }

public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        fillNodes(nodes, head);
        int left = 0, right = nodes.size() - 1;
        ListNode* current = head;
        while (left <= right) {
            current = updateCurrent(current, nodes[left]);
            left++;
            if (left <= right) {
                current = updateCurrent(current, nodes[right]);
                right--;
            }
        }
        current->next = nullptr;
    }
};
