class MedianFinder {
public:
    vector<int> elements_;   
    MedianFinder() {
      vector<int> elements_;   
    }
    
    void addNum(int num) {
      elements_.push_back(num);  
    }
    
    double findMedian() {
        sort(elements_.begin(), elements_.end());
        if (elements_.size() % 2 != 0) {
            return elements_[elements_.size() / 2];
        }
        double first = elements_[elements_.size() / 2 - 1];
        double second = elements_[elements_.size() / 2];
        return (first + second) / 2;
    }
};
