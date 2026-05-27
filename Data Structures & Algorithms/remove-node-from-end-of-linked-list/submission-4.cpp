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
        ListNode* new_head = reverse(head);
        ListNode* curr = new_head;
        if (n == 1) {
            new_head = new_head->next;
            return reverse(new_head);
        }
        for (int i = 0; i < n - 2; i++) {
            if (!curr) {
                return nullptr;
            }
            curr = curr->next;
        }
        removeNode(curr);
        return reverse(new_head);
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void removeNode(ListNode* curr) {
        curr->next = curr->next->next;
    }
};
