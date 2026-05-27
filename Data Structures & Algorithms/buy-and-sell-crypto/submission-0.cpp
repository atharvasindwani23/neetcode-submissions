class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lower = 0;
        int upper = 1;
        int profit = 0;
        while (upper < prices.size()) {
            if (prices[upper] > prices[lower]) {
                profit = max(profit, prices[upper] - prices[lower]);
            } else {
                lower = upper;
            }
            upper++;
        }
        return profit;
    }
};
