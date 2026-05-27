class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> elements;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            elements.push(num);
            if (elements.size() > k) {
                elements.pop();
            }
        }
    }
    
    int add(int val) {
        if (elements.size() < k) {
            elements.push(val);
        } else if (val > elements.top()) {
            elements.pop();
            elements.push(val);
        }
        return elements.top();
    }
};
