class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = nums[0];
        int minn = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(maxx, minn);
            
            maxx = max(nums[i], maxx * nums[i]);
            minn = min(nums[i], minn * nums[i]);
            
            ans = max(ans, maxx);
        }
        return ans;
    }
};
