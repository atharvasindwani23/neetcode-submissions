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
    int pairSum(ListNode* head) {
        vector<int> origList;
        ListNode* copy = head;
        while (copy) {
            origList.push_back(copy->val);
            copy = copy->next;
        }
        ListNode* rev = reverse(head);

        int maximum = 0;
        int count = 0;

        while (rev) {
            maximum = max(maximum, origList[count] + rev->val);
            rev = rev->next;
            count++;
        }
        return maximum;
    }

    //reverse the list and calculate the sums as you go on;

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};