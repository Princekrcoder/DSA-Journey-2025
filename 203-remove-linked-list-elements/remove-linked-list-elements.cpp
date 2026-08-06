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
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr && head->val == val) {
            head = head->next;
        }
        if(head == nullptr || (head->val == val && head->next == nullptr )) {
            return nullptr;
        }

        ListNode* temp = head;
        ListNode* tail = temp->next;

        while(tail != nullptr) {
            if(tail->val == val){
                temp->next = tail->next;
                tail = tail->next;
            } else{
                temp = tail;
                tail = tail->next;
            }
        }

        return head;
    }
};