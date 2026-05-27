class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lower = 0;
        int upper = heights.size() - 1;
        int result = 0;
        while (lower < upper) {
            int area = min(heights[lower], heights[upper]) * (upper - lower);
            result = max(area, result);
            if (heights[lower] < heights[upper]) {
                lower++;
            } else {
                upper--;
            }
        }
        return result;
    }
};
