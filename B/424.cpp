class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0, maxCount = 0;
        int start = 0;
        for (int end = 0; end < s.length(); end++) {
            maxCount = max(maxCount, ++count[s[end] - 'A']);
            
            if (end - start + 1 - maxCount > k) {
                count[s[start++] - 'A']--;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
    
private:
    int count[27];
};
