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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = reverse(head);
        cout << newHead->val << endl;
        ListNode* curr = newHead;
        if (n == 1) {
            newHead = newHead->next;
            return reverse(newHead);
        }
        for (int i = 0; i < n - 2; i++) {
            curr = curr->next;
        }
        curr->next = (curr->next)->next;
        return reverse(newHead);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }
        return prev;
    }
};
