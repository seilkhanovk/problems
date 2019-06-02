class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1);
        for (int i = 1; i <= num; i++) {
            int cnt = 0;
            int n = i;
            while (n) {
                n = n & (n - 1);
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
