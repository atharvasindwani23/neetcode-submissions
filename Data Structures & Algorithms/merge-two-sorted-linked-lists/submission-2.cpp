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
        ListNode* curr = new ListNode(-1, nullptr);
        ListNode* finalHead = curr;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                curr->next = list2;
                list2 = list2->next;
            } else {
                curr->next = list1;
                list1 = list1->next;
            }
            curr = curr->next;
        }
        if (list1) {
            curr->next = list1;
        }
        if (list2) {
            curr->next = list2;
        }
        return finalHead->next;
    }
};
