class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
           }  // tie-breaker
            return a[1] < b[1];
        });
       int returner = 0;
       int lower = 0;
       int upper = 1;
       while (upper < intervals.size()) {
          if (helper(intervals[lower], intervals[upper])) {
            returner++;
            upper++;
          } else {
            lower = upper;
            upper++;
          }
       }
       return returner;
    }
    bool helper(vector<int> first, vector<int> second) {
        return (first[1] > second[0]);
    }
};
