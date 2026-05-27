class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals by end time (greedy strategy)
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];  // key change
        });

        int returner = 0;
        int lower = 0;
        int upper = 1;

        while (upper < intervals.size()) {
            // Check if current interval overlaps with the previous one
            if (intervals[upper][0] < intervals[lower][1]) {
                returner++;  // overlap → remove current interval
                upper++;     // move forward, lower stays to compare with the next
            } else {
                lower = upper;  // no overlap → accept current, move both
                upper++;
            }
        }

        return returner;
    }
};
