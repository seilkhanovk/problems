class Solution {
    public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.length() == 0 || words.size() == 0) return {};
        unordered_map<string, int> dict;
        int wordLen = words[0].length();
        int windowLen = words.size() * wordLen;
        for (string word: words) dict[word]++;
        
        unordered_map<string, int> reference(dict);
        vector<int> positions;
        int missingWords = words.size();
        
        if (s.length() < windowLen) return{};
        
        for (int i = 0; i < wordLen; i++) {
            int begin = i, end = i;
            dict = reference;
            missingWords = words.size();
            while (end < s.length() - wordLen + 1) {
                
                string word = s.substr(end, wordLen);
                
                if (dict.count(word) == 1) {
                    dict[word]--;
                    if (dict[word] >= 0) missingWords--;
                }
                
                if (end + wordLen - begin == windowLen) {
                    // cout<<word<<" "<<missingWords<<endl;
                    if (missingWords == 0) {
                        positions.push_back(begin);
                    }
                    
                    word = s.substr(begin, wordLen);
                    if (dict.count(word) == 1) {
                        dict[word]++;
                        if (dict[word] > 0) missingWords++;
                    }
                    begin+=wordLen;
                }
                
                end+=wordLen;
            }
        }
        return positions;
    }
};
