class Solution {
public:
    int solve(int i, vector<int> &dp) {
        // BASE CASE
        if(i == 0) return 0;
        // BASE CASE
        if(i == 1 || i == 2) return 1;

        if(dp[i] !=  -1) return dp[i];
        
        // recursive function but optimized because we are storing values into dp table
        return dp[i] = solve(i - 1, dp) + solve(i - 2, dp) + solve(i - 3, dp);
    }

    int tribonacci(int n) {
        // dp array of n + 1 size
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};