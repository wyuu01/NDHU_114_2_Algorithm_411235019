class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int limit = 2 * k + 1;
        vector<int> avgs(n, -1);
        if(limit>n) return avgs;
        long long sum = 0;
        for(int i=0; i<limit; i++){
            sum = sum + nums[i];
        }
        avgs[k] = sum / limit;
        for(int i=limit; i<n; i++){
            sum = sum + nums[i];
            sum = sum - nums[i-limit];
            avgs[i-k] = sum / limit;
        }
        return avgs;
    }
};