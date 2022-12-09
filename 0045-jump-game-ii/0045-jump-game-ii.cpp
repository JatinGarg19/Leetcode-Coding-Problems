class Solution {
public:
    int jump(vector<int>& nums) {
        // create a dp array of size n + 1 and initialize it with -1.
        vector<int> dp(nums.size()+1, -1);
        
        // return solve function
        return solve(nums, 0, dp);
    }

    int solve(vector<int>& nums, int idx, vector<int>& dp) {
        // if idx >= n - 1, return 0.
        if(idx >= nums.size() - 1) return 0;

        if(dp[idx] != -1) return dp[idx];

        int k = nums[idx];
    
        // minJumps cannot be greater than 1000. i.e max value of nums[i].
        int min_jumps = 10001;

        // run a for loop from 1 till nuks[idx].
        for(int j = 1; j <= k; j++) {
            // minJumps will be min of minJumps and f(nums, idx + j);
            min_jumps = min(min_jumps, 1 + solve(nums, idx + j, dp));
        }
        return dp[idx] = min_jumps;     // TC-O(N*N), SC-O(N).
    }
};