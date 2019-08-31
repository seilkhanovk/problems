class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> m(128, 0);
        for (char c: t) m[c]++;
        int start = 0, end = 0, counter = t.length(), minLen = INT_MAX, ansStart = 0;
        while (end < s.length()) {
            if (m[s[end]] > 0) counter--;
            
            m[s[end]]--;
            end++;
            
            while (counter == 0) {
                if (minLen > end - start) {
                    minLen = end - start;
                    ansStart = start;
                }
                
                m[s[start]]++;
                
                if (m[s[start]] > 0) counter++;
                
                start++;
            }
        }
        if (minLen != INT_MAX) {
            return s.substr(ansStart, minLen);
        }
        return "";
    }
};
