class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> weights;

       for (int stone : stones) {
            weights.push(stone);
       }

       while (weights.size() > 1) {
            int heaviest = weights.top();
            weights.pop();
            int secondHeaviest = weights.top();
            weights.pop();

            if (heaviest != secondHeaviest) {
                weights.push(heaviest - secondHeaviest);
            }
       }
        if (weights.size() == 0) {
            return 0;
        } 
        return weights.top();
    }
};
