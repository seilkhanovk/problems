class Solution {
    public:
    int longestSubstring(string s, int k) {
        int start = 0, end = 0, unique = 0, kElements = 0;
        unordered_map<char, int> freq;
        int maxLen = 0;
        for (int i = 1; i <= 26; i++) {
            freq.clear();
            unique = 0;
            kElements = 0;
            start = 0;
            end = 0;
            while (end < s.length()) {
                if (unique <= i) {
                    freq[s[end]]++;
                    if (freq[s[end]] == 1) unique++;
                    if (freq[s[end]] == k) kElements++;
                    end++;
                }else {
                    freq[s[start]]--;
                    if (freq[s[start]] == 0) unique--;
                    if (freq[s[start]] == k - 1) kElements--;
                    start++;
                }
                if (unique == i && kElements == i) maxLen = max(maxLen, end - start);
            }
        }
        return maxLen;
    }
};
