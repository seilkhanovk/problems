class Solution {
public:
    
    void explore(vector<int>& nums, int target, int start) {
        if (target == 0 && combination.size() != 0) {
            allCombinations.push_back(combination);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i - 1] == nums[i]) continue;
            combination.push_back(nums[i]);
            explore(nums, target - nums[i], i + 1);
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        for (int candidate: candidates) {
            if (candidate > target) break;
            nums.push_back(candidate);
        }
        explore(nums, target, 0);
        return allCombinations;
    }
private:
    vector<vector<int>> allCombinations;
    vector<int> combination;
};
