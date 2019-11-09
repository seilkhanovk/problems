class Solution {
public:
    
    void backtrack(vector<int> nums, int target, int k) {
        if (target == 0 && combinations.size() != 0) {
            allCombinations.push_back(combinations);
            return;
        }
        if (target < 0) return;
        for (int i = k; i < nums.size(); i++) {
            target -= nums[i];
            combinations.push_back(nums[i]);
            backtrack(nums, target, k);
            target += nums[i];
            k++;
            combinations.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return allCombinations;
    }
private:
    vector<vector<int>> allCombinations;
    vector<int> combinations;
};
