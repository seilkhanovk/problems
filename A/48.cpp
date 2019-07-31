class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (!n || n == 1) return;
        int m = n;
        int i = 0;
        while (n > 1) {
            for (int j = i; j < m - 1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[m - 1 - j + i][i];
                matrix[m - 1 - j + i][i] = matrix[m - 1][m - 1 - j + i];
                matrix[m - 1][m - 1 - j + i] = matrix[j][m - 1];
                matrix[j][m - 1] = temp;
            }
            i++;
            n-=2;
            m--;
        }
    }
};
