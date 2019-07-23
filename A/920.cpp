/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    
    bool canAttendMeetings(vector<Interval> &intervals) {
        auto comp = [](const Interval& i1, const Interval& i2){ return i1.start < i2.start; };
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        bool ans = true;
        for (int i = 1; i < n; i++) {
            if (intervals[i].start < intervals[i - 1].end) ans = false;
        }
        return ans;
    }
};
