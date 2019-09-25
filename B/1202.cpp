class Solution {
public:
    unordered_map<int, vector<int>> g;
    vector<bool> visited;
    
    void dfs(int i, vector<int>& index) {
        if (visited[i]) return;
        index.push_back(i);
        visited[i] = true;
        for (auto v: g[i]) dfs(v, index);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for (auto &p: pairs) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        visited.resize(s.length(), false);
        for (int i = 0; i < s.length(); i++) {
            if (visited[i]) continue;
            vector<int> index;
            dfs(i, index);
            sort(index.begin(), index.end());
            string temp = "";
            for (int i = 0; i < index.size(); i++) {
                temp += s[index[i]];
            }
            sort(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); i++) {
                s[index[i]] = temp[i];
            }
        }
        return s;
    }
};
