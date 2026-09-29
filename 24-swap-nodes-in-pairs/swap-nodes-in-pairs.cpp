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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        head = head->next;
        ListNode* prev = NULL;
        while(temp != NULL && temp->next != nullptr){
            ListNode* curr = temp;
            ListNode* front = temp->next;

            curr->next = front->next;
            front->next = curr;

            if(prev!=NULL){
                prev->next = front;
            }
            prev = curr;
            temp = curr->next;
            
        }
        return head;
    }
};