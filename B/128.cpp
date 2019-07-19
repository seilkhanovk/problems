class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            int target = -nums[i];
            int front = i + 1;
            int back = n - 1;
            
            if (target < 0) break;
            
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum < target) front++;
                else if (sum > target) back--;
                else {
                    ans.push_back({nums[i], nums[front], nums[back]});
                    
                    while (front + 1 < back && nums[front + 1] == nums[front]) front++;
                    while (front < back - 1 && nums[back - 1] == nums[back]) back--;
                    front++;
                    back--;
                }
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};
