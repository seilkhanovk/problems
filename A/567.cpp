class Solution {
    public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> dict;
        if ((s1.length() == 0 && s2.length() == 0) || (s1.length() > s2.length())) return false;
        int missingCh = 0;
        for (char ch: s1) {
            if (!dict[ch]) missingCh++;
            dict[ch]++;
        }
        int start = 0, end = 0;
        
        for (; end < s2.length(); end++) {
            if (missingCh == 0) return true;
            if (dict.count(s2[end]) == 1) {
                dict[s2[end]]--;
                if (dict[s2[end]] == 0) missingCh--;
            }
            
            if (end < s1.length()) continue;
            
            if (dict.count(s2[start]) == 1) {
                dict[s2[start]]++;
                if (dict[s2[start]] == 1) missingCh++;
            }
            start++;
        }
        if (missingCh == 0) return true;
        return false;
    }
};
