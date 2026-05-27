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
        std::map<ListNode*, bool> visited;
        ListNode* copier = head;
        while (copier) {
            if (visited[copier]) {
                return true;
            }
            visited[copier] = true;
            copier = copier->next;
        }
        return false;
    }
};
