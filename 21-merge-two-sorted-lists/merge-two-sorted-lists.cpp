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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val < list2->val) {

                ListNode* newNode = new ListNode(list1->val);

                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }

                list1 = list1->next;
            }

            else if (list1->val > list2->val) {

                ListNode* newNode = new ListNode(list2->val);

                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }

                list2 = list2->next;
            }

            else {

                // list1 wala node
                ListNode* newNode1 = new ListNode(list1->val);

                if (head == nullptr) {
                    head = newNode1;
                    tail = newNode1;
                } else {
                    tail->next = newNode1;
                    tail = newNode1;
                }

                // list2 wala node
                ListNode* newNode2 = new ListNode(list2->val);

                tail->next = newNode2;
                tail = newNode2;

                list1 = list1->next;
                list2 = list2->next;
            }
        }

        while (list1 != nullptr) {

            ListNode* newNode = new ListNode(list1->val);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            list1 = list1->next;
        }

        while (list2 != nullptr) {

            ListNode* newNode = new ListNode(list2->val);

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            list2 = list2->next;
        }

        return head;
    }
};