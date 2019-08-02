class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, int i, int j, int ind, string word) {
        if (ind == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (board[i][j] != word[ind]) return false;
        
        board[i][j] = '*';
        bool isExist = dfs(board, i - 1, j, ind + 1, word) ||
        dfs(board, i + 1, j, ind + 1, word) ||
        dfs(board, i, j + 1, ind + 1, word) ||
        dfs(board, i, j - 1, ind + 1, word);
        
        board[i][j] = word[ind];
        return isExist;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (!n) return false;
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
};
