class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minVal = INT_MAX;
        for (int i=0;i<prices.size();i++) {
            minVal = min(prices[i], minVal);
            maxProf = max(maxProf, prices[i] - minVal);
        }
        return maxProf;
    }
};
