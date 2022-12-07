class Solution {
public:
    bool solve(vector<int>& nums, int ind, vector<int>& dp) {
        // If idx reaches to the last element, we are successful.
        if(ind == nums.size() - 1) return true;

        // If we bychance cross the last element, return false
        if(ind >= nums.size()) return false;

        if(dp[ind] != -1) return dp[ind];

        // Initialize k as value at that idx.
        int k = nums[ind];
        
        // Run a for loop from 1 till value of that idx.
        for(int i = 1; i <= k; i++) {
            if(solve(nums, ind + i, dp) == true) {
                return dp[ind] = 1;
            }
        }
        return dp[ind] = 0;
    }

    bool canJump(vector<int>& nums) {
        // create a dp array of size n, initialize it to -1.
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};