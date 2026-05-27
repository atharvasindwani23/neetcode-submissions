class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lower = 0;
        int upper = heights.size() - 1;
        int max_area = 0;
        while (lower <= upper) {
            int height = min(heights[lower], heights[upper]);
            int dist = (upper - lower);
            max_area = max(max_area, dist * height);
            if (heights[lower] < heights[upper]) {
                lower++;
            } else {
                upper--;
            }
        }
        return max_area;
    }



    //very clear example of a two ptr q
};
