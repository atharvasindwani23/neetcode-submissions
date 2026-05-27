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
    bool hasCycle(ListNode* head) {
        set<ListNode*> visited;
        ListNode* curr = head;
        while (curr) {
            if (visited.count(curr)) {
                return true;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};
