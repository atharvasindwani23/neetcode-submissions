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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummy = new ListNode();
      ListNode* curr = dummy;
      int carry = 0;
      while (l1 != nullptr || l2 != nullptr || carry != 0) {

        int value_1 = 0;
        int value_2 = 0;
        if (l1 != nullptr) {
            value_1 = l1->val;
        }
        if (l2 != nullptr) {
            value_2 = l2->val;
        }

        int val = value_1 + value_2 + carry;
        carry = val / 10;
        val = val % 10;
        curr->next = new ListNode(val);

        curr = curr->next;

        if (l1 != nullptr) {
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            l2 = l2->next;
        }
        
      } 
      ListNode* res = dummy->next;
      delete dummy;
      return res;
    }
};
