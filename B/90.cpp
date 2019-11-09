class Solution {
public:
    
    void makeSubset(vector<int> nums, int ind) {
        allSubset.push_back(subset);
        for (int i = ind; i < nums.size(); i++) {
            if (i > ind && nums[i - 1] == nums[i]) continue;
            subset.push_back(nums[i]);
            makeSubset(nums, i + 1);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        makeSubset(nums, 0);
        return allSubset;
    }
    
private:
    vector<int> subset;
    vector<vector<int>> allSubset;
};
