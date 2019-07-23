class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int x = newInterval[0], y = newInterval[1];
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] >= newInterval[0]) {
                x = min(intervals[i][0], newInterval[0]);
                break;
            }
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] <= newInterval[1]) {
                y = max(intervals[i][1], newInterval[1]);
            }
        }
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] <= y && intervals[i][0] >= x) continue;
            ans.push_back(intervals[i]);
        }
        ans.push_back({x, y});
        sort(ans.begin(), ans.end());
        return ans;
    }
};
