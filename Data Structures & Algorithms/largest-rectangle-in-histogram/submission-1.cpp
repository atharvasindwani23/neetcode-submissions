class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st; // pair: (index, height)

        for (int i = 0; i < heights.size(); ++i) {
            int start = i;
            while (!st.empty() && st.top().second > heights[i]) {
                auto [index, height] = st.top();
                st.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            st.push({start, heights[i]});
        }

        int n = heights.size();
        while (!st.empty()) {
            auto [index, height] = st.top();
            st.pop();
            maxArea = max(maxArea, height * (n - index));
        }

        return maxArea;
    }
};
