class Solution {
public:
    
    int gcd(int a, int b) {
        if (a == 0) return b;
        return (b%a, a);
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long aa = long(a), bb = long(b), cc = long(c);
        long ab = aa*bb/__gcd(aa, bb);
        long ac = aa*cc/__gcd(aa, cc);
        long bc = bb*cc/__gcd(bb, cc);
        long abc = aa*bc/__gcd(aa, bc);
        int l = 1, r = INT_MAX;
        int cnt = 0;
        while (l < r) {
            int num = l + (r - l)/2;
            cnt = num/a + num/b + num/c - num/ab - num/ac - num/bc + num/abc;
            if (cnt < n) {
                l = num + 1;
            }else
                r = num;
        }
        return l;
    }
};
