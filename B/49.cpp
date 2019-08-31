class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for (string str: strs) {
            string sortedStr = sortStr(str);
            mp[sortedStr].push_back(str);
        }
        
        for (auto p: mp) {
            ans.push_back(p.second);
        }
        return ans;
    }
    
private:
    string sortStr(string s) {
        vector<int> count(27, 0);
        for (char c: s) {
            count[c - 'a']++;
        }
        string str;
        for (int i = 0; i < 26; i++) {
            str += string(count[i], i + 'a');
        }
        return str;
    }
};
