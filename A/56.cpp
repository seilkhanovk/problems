class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n == 0) return {};
        vector<vector<int>> ans;
        int curx = intervals[0][0];
        int cury = intervals[0][1];
        for (int i = 1; i < n; i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];
            if (cury >= x) {
                if (cury < y)
                    cury = y;
            }else
                if (curx < x && cury < y) {
                    ans.push_back({curx, cury});
                    cout<<curx<<" "<<cury<<endl;
                    curx = x;
                    cury = y;
                }else
                    if (curx == x || cury < y) {
                        cury = y;
                    }
        }
        ans.push_back({curx, cury});
        return ans;
    }
};
