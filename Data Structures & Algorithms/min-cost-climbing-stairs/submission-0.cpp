class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int> stairCost(cost.size(), 0);
       stairCost[cost.size() - 1] = cost[cost.size() - 1];
       stairCost[cost.size() - 2] = cost[cost.size() - 2];
       int n = cost.size();
       for (int i = n - 3; i >= 0; i--) {
        stairCost[i] = cost[i] + min(stairCost[i + 1], stairCost[i + 2]);
       }
       return min(stairCost[0], stairCost[1]); 
    }
};
