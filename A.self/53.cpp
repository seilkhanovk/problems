class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return {};
        vector<int> sums(nums);
        int maxSum = nums[0];
        for (int i=1;i<nums.size();i++) {
            sums[i] = max(nums[i], sums[i-1] + nums[i]);
            maxSum = max(maxSum, sums[i]);
        }
        return maxSum;
    }
};
