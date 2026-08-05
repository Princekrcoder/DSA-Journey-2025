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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* temp = head;
        ListNode* tail = head->next;

        while (tail != nullptr) {

            if (temp->val == tail->val) {
                temp->next = tail->next;
                tail = tail->next;
            }
            else {
                temp = tail;
                tail = tail->next;
            }
        }

        return head;
    }
};