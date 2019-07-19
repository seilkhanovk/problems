class Solution {
public:
    
    void dfs(int i) {
        visited[i] = true;
        for (int u: g[i]) {
            if (!visited[u]) {
                dfs(u);
            }else {
                if (entrance == u)
                    ans = false;
            }
        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); i++) {
            int x = prerequisites[i][1];
            int y = prerequisites[i][0];
            g[x].push_back(y);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                entrance = i;
                dfs(i);
            }
            if (!ans) {
                return false;
            }
            for (int j = i + 1; j < numCourses; j++)
                visited[j] = false;
        }
        return true;
    }
private:
    bool visited[100000];
    vector<int> g[100000+9];
    int entrance;
    bool ans = true;
};
