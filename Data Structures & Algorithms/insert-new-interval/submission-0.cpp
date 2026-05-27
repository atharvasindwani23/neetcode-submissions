class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] > newInterval[1]) {
                res.push_back(newInterval);
                for (int start = i;  start < intervals.size(); start++) {
                    res.push_back(intervals[start]);
                }
                return res;
            } else if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            } else {
                newInterval = {min(newInterval[0], intervals[i][0]), max(intervals[i][1], newInterval[1])};
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
