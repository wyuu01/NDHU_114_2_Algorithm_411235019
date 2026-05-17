class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        int from1_curr = 0;
        int from1_prev = 0;
        for (int i = 0; i < n - 1; i++) {
            int temp = max(from1_curr, from1_prev + nums[i]);
            from1_prev = from1_curr;
            from1_curr = temp;
        }

        int from2_curr = 0;
        int from2_prev = 0;
        for (int i = 1; i < n; i++) {
            int temp = max(from2_curr, from2_prev + nums[i]);
            from2_prev = from2_curr;
            from2_curr = temp;
        }

        return max(from1_curr, from2_curr);
    }
};