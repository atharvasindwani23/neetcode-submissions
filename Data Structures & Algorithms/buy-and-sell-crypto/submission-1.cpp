class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lower = 0;
        int upper = 1;
        int res = 0;
        while (upper < prices.size()) {
            if (prices[lower] > prices[upper]) {
                lower = upper;
            } else {
                res = max(prices[upper] - prices[lower], res);
            }
            upper++;
        }
        return res;
    }


    //[10, 1, 5, 6, 7, 1]

    //max diff bw arr[j] - arr[i] where j > i

    //naive approach is to do it in a O(n^2) approach
    // can optimize it by using pointers to move along stuff 
};
