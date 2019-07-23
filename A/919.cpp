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
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        auto comp = [](const Interval& i1, const Interval& i2) {return (i1.start < i2.start); };
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> v;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            bool ok = false;
            for (int j = 0; j < v.size(); j++) {
                if (v[j].end < intervals[i].start) {
                    v[j] = intervals[i];
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                v.push_back(intervals[i]);
            }
        }
        return v.size();
    }
};
// [(567707,730827),(166232,719216),(634677,756013),(285191,729059),(237939,915914),(201296,789707),(578258,585240),(164298,218749)]
