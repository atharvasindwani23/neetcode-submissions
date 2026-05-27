class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> elements;
        for (int num : nums) {
            elements.push(num);
        }
        int curr = 0;
        for (int i = 0; i < k; i++) {
            curr = elements.top();
            elements.pop();
        }
        return curr;
    }
};
