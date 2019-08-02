class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> sMap(0);
        unordered_map<char, int> tMap(0);
        
        for (int i = 0; i < s.length(); i++) {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (sMap[s[i]] != tMap[s[i]]) return false;
        }
        return true;
    }
};
