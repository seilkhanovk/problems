class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        vector<int> freq(A.size() + 1);
        int l = 0, prefix = 0, cnt = 0, ans = 0;
        for (int r = 0; r < A.size(); r++) {
            if (freq[A[r]] == 0) {
                cnt++;
            }
            freq[A[r]]++;
            if (cnt > K) {
                freq[A[l++]]--;
                cnt--;
                prefix = 0;
            }
            while (freq[A[l]] > 1) {
                freq[A[l]]--;
                l++;
                prefix++;
            }
            if (cnt == K) ans += prefix + 1;
        }
        return ans;
    }
};
