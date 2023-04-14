class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        
        return lis(nums, 0, -1, dp);
    }
    
    int lis(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
        if(idx == nums.size()) return 0;
        
        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        
        int notTake = 0 + lis(nums, idx + 1, prevIdx, dp);
        
        int take = 0;
        
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            take = 1 + lis(nums, idx + 1, idx, dp);
        }
        
        return dp[idx][prevIdx+1] = max(notTake, take);
    }
};