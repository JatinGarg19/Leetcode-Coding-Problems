class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0; i < n; i++) {
            totSum += nums[i];
        }
        
        if(totSum % 2 != 0) return false;
        
        int target = totSum/2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return func(nums, n - 1, target, dp);
    }
    
    bool func(vector<int>& nums, int idx, int target, vector<vector<int>>& dp) {
        if(target == 0) return true;
        if(idx == 0) return (nums[idx] == target);
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        // either take or not take
        bool nottake = func(nums, idx - 1, target, dp);
        bool take = false;
        if(target >= nums[idx]) {
            take = func(nums, idx - 1, target - nums[idx], dp);
        }
        
        return dp[idx][target] = take or nottake;
    }
};