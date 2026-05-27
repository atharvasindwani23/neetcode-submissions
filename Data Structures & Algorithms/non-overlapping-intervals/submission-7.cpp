class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int res = 0;
        for (int i = 0; i < intervals.size() - 1; i++) {
            int curr_end = intervals[i][1];
            int next_start = intervals[i + 1][0];
            int next_end = intervals[i + 1][1];
            if (curr_end > next_start) {
                res++;
                if (next_end > curr_end) {
                    intervals[i + 1] = intervals[i];
                }
            }
        }
        return res;
    } 
};
