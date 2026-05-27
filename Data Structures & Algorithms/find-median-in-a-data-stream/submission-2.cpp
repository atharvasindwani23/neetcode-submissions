class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }   
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            cout << minHeap.top() << endl;
            cout << maxHeap.top() << endl;
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }
    }
};
