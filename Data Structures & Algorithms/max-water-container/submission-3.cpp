class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maximum = 0;
        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            maximum = max(maximum, area);

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maximum;
    }
};
