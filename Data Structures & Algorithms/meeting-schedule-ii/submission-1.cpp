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
    int minMeetingRooms(vector<Interval>& intervals) {

        



        vector<int> startTime;
        vector<int> endTime;

        for (Interval interval : intervals) {
            startTime.push_back(interval.start);
            endTime.push_back(interval.end);
        }
        
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
    

        int count = 0;
        int res = 0;
        int start = 0;
        int end = 0;

        while (start < intervals.size()) {
            if (startTime[start] < endTime[end]) {
                start++;
                count++;
            } else {
                end++;
                count--;
            }
            res = max(res, count);
        }
        return res;
    }
};
