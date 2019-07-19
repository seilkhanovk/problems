class Solution {
public:
    
    void bfs(int i, int j, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int c = 0; c < 4; c++) {
                int dx = x + dirc[c][0];
                int dy = y + dirc[c][1];
                if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
                if (visited[dx][dy] || grid[dx][dy] == '0') continue;
                q.push({dx, dy});
                visited[dx][dy] = true;
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n == 0) return {};
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, grid);
                }
            }
        }
        return ans;
    }
private:
    bool visited[1000][1000];
    int dirc[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int n, m;
};
