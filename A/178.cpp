class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    
    void dfs(int u) {
        visited[u] = true;
        for (int i = 0; i < g[u].size(); i++) {
            int edge = g[u][i];
            if (!visited[edge]) {
                dfs(edge);
            }else {
                ans = false;
                break;
            }
        }
    }
    
    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() == 0) {
            if (n == 1) return true;
            return false;
            
        }
        set<int> s;
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            s.insert(x);
            s.insert(y);
            g[x].push_back(y);
            // g[edges[i][1]].push_back(edges[i][0]);
        }
        if (s.size() != n) return false;
        bool exist[n + 9];
        for (int i = 0; i < n; i++) {
            dfs(i);
            memset(visited, false, n);
        }
        return ans;
    }
private:
    bool ans = true, visited[100000];
    vector<int> g[100000];
};
