class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n==0) return {};
        int m = matrix[0].size();
        int numElem = n*m;
        int a, b, c, d, e, cnt = 0;;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (cnt == numElem) break;
            //right
            for (b = i; b < m - i; b++) {
                ans.push_back(matrix[i][b]);
                cnt++;
            }
            b--;
            if (cnt == numElem) break;
            //down
            for (c = i + 1; c < n - i; c++) {
                ans.push_back(matrix[c][b]);
                cnt++;
            }
            c--;
            
            if (cnt == numElem) break;
            //left
            for (d = m - i - 2; d >= i; d--) {
                ans.push_back(matrix[c][d]);
                cnt++;
                
            }
            d++;
            if (cnt == numElem) break;
            //up
            for (e = n - i - 2; e >= i + 1; e--) {
                ans.push_back(matrix[e][d]);
                cnt++;
            }
        }
        return ans;
    }
};
