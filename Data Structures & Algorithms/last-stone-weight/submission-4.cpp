class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weights;
        for (int i = 0; i < stones.size(); i++) {
            weights.push(stones[i]);
        }
        while (weights.size() > 1) {
            int first = weights.top();
            weights.pop();
            int second = weights.top();
            weights.pop();
            if (first != second) {
                weights.push(first - second);
            } 
        }
        if (weights.size() == 0) {
            return 0;
        }
        return weights.top();
    }
};
