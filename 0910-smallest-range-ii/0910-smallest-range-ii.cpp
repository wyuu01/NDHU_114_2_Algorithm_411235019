class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n-1] - nums[0];
        for (int i = 1; i < n; i++){
            int up = max(nums[i-1]+k, nums[n-1]-k);
            int low = min(nums[i]-k, nums[0]+k);
            ans = min(ans, up-low);
        }
        return ans;
    }
};