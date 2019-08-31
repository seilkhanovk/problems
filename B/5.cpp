class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        for (int i = 0; i < s.length() - 1; i++) {
            extendPalindrome(s, i, i);
            extendPalindrome(s, i, i + 1);
        }
        return s.substr(lo, maxLen);
    }
    
private:
    int maxLen, lo;
    void extendPalindrome(string s, int j, int k) {
        while (j >=0 && k < s.length() && s[j] == s[k]) {
            j--;
            k++;
        }
        j++;
        k--;
        if (maxLen < k - j + 1) {
            maxLen = k - j + 1;
            lo = j;
        }
    }
};
