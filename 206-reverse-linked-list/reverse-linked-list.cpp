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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == nullptr) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* front = head->next;
        ListNode* curr = head;
        while(curr!= NULL) {
            curr->next = prev;
            prev = curr;
            curr = front;
            if(front) front = front->next;
        }
        return prev;
    }
};