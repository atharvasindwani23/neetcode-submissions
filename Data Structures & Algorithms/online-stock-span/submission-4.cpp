class StockSpanner {
public:
    vector<int> elements;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (elements.empty()) {
            elements.push_back(price);
            return 1;
        }
        int n = elements.size();
        elements.push_back(price);
        for (int i = n; i >= 0; i--) {
            if (elements[i] > price) {
                return n - i;
            }
        }
        return elements.size();
    }

    //how many days have elapsed such that the price in our array is > curr price
    //ie if we have an array of size n, and price is 10, idx i has a price 11 and remaining have prices 1
    //then n - i will be the answer.


    //goal is to find the last index i such that arr[i] > price.
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */