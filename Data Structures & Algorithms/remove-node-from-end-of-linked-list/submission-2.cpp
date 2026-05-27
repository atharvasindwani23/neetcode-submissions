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
        int len = length(head); //2nd ele from the end is (6 - 2 + 1)th element from the front
        std::cout << len << std::endl;
        if (len == 1) {
            return nullptr;
        }
        int forward = len - n + 1;
        if (forward == 1) {
            head = head->next;
            return head;
        }
        std::cout << forward << std::endl;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < forward - 2; i++) {
            curr = curr->next;
        }
        std::cout << curr->val << std::endl;
        prev = curr;
        prev->next = prev->next->next;
        return head;
    }
 
    int length(ListNode* head) {
        int returner = 0;
        while (head) {
            returner += 1;
            head = head->next;
        }
        return returner;
    }

    //nth node from the end will be what node from the front first figure that out
    //we will need a helper function which returns length of linked list 
};
