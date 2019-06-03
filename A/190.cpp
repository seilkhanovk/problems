class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int r = 31, l = 0;
        while (r) {
            int num = n & (1<<r);
            if (num) {
                ans = ans | (1<<l);
            }
            r--;
            l++;
        }
        if (n & 1) {
            ans = ans | (1<<l);
        }
        return ans;
    }
};
