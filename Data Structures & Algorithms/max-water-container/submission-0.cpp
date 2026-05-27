class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lower = 0;
        int upper = heights.size() - 1;
        int area = 0;
        while (lower < upper) {
            int temp = min(heights[lower],heights[upper]) * (upper - lower);
            area = max(area, temp);
            if (heights[lower] < heights[upper]) {
                lower++;
            } else {
                upper--;
            }
        }
        return area;
    }


    // diff of coordinates * min height of two pillars
    // its a bit difficult to think in exactly what order we should evaluate this
    // one strategy is that we have two pointers at exteme ends again
    // q then is how do we bring them together
    //like whats the condition to update one of the ptrs [maybe the one with the lesser height?]
};
