class KthLargest {

private:

priority_queue<int> q;
int k;

public:
    KthLargest(int k, vector<int>& nums) {
     this->k = k;
     for (int num : nums) {
        q.push(-1 * num);
     }
     while (q.size() > k) {
        q.pop();
     }

    }
    
    int add(int val) {
        q.push(-1 * val);
        if (q.size() > k) {
        q.pop();
        }
        return q.top() * -1;    
    }
};


//min heap => heres the logic, if i have a sorted array of 5 elements and someone asks me whats the 5th largest element, itll be the one at the top ALWAYS
//that's the key thing to figure out here
//why does a min heap not work? think about it logically, in an array of 5 elements the 5th largest in that case will be the one at the end which will require immense popping and reinsertion we want to avoid this

