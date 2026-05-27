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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr->next) {
            ListNode* temp = curr->next;
            int gc = gcd(curr->val, temp->val);
            curr->next = new ListNode(gc, temp);
            curr = temp;
        }
        return head;
    }

    int gcd(int first, int second) {
        int res = 1;
        for (int i  = 1; i <= min(first, second); i++) {
            if (first % i == 0 && second % i == 0) {
                res = i;
            }
        }
        return res;
    }
};