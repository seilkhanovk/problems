class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int fromStart = 1;
        int fromLast = 1;
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            res[i] *= fromStart;
            res[n - i - 1] *= fromLast;
            fromStart *= nums[i];
            fromLast *= nums[n - i - 1];
        }
        return res;
    }
};
