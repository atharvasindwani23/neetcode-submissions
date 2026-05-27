class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
        }
        int c = 0;
        while(pq.size() != 0) {
            int x = pq.top();
            pq.pop();
            c++;
            if (c == k) {
                return x;
            }
        }
        return -1;
    }
};
