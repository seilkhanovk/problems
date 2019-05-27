class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        int piv = l;
        cout<<piv;
        l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int realMid = (piv + mid) % nums.size();
            if (nums[realMid] == target) return realMid;
            if (nums[realMid] < target) l = mid + 1;else
                r = mid - 1;
        }
        return -1;
    }
};
