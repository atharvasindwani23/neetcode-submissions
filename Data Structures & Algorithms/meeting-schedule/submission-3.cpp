/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        if (intervals.size() == 0) {
            return true;
        }

        for (int i = 0; i < intervals.size() - 1; i++) {
            int curr_end = intervals[i].end;
            int next_start = intervals[i + 1].start;
            if (curr_end > next_start) {
                return false;
            }
        }
        return true;
    }
};
