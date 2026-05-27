class KthLargest {
public:
    priority_queue<int> pq;
    int largest = 0;
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            pq.push(num);
        }
        largest = k;
    }
    
    int add(int val) {
        pq.push(val);
        vector<int> c;
        for (int i  = 0; i < largest - 1; i++) {
            c.push_back(pq.top());
            pq.pop();
        }
        int res = pq.top();
        for (int ele : c) {
            pq.push(ele);
        }
        return res;
    }
};
