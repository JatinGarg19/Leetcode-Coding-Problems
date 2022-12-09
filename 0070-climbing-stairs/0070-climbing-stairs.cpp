class Solution {
public:
    int solve(int n, vector<int> &dp) {
        // If there are no staircase, return 0.
        if(n < 0) return 0;

        // If stairs are zero or only 1, then return 1.
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        // a person can jump to nth stair either from (n-1)st stair or (n-2)nd stair.
        // return all possible ways.
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int climbStairs(int n) {
        // dp array of size n + 1. Initialize it with -1.
        vector<int> dp(n + 1, -1);
        
        // solve function
        return solve(n, dp);
    }
};