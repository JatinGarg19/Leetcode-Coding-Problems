class Solution {
public:
    const int MOD = 1e9+7;
    int dp[1001][2]{};
    
    
    long solve(int n, int i, bool prevGap) {
        // previous tiling exceeded bounds of grid
        if(i > n) return 0;
        
        // return 1 when there was no previous gap present.
        if(i == n) return !prevGap;
        
        if(dp[i][prevGap]) return dp[i][prevGap];
        
        if(prevGap)
            return dp[i][prevGap] = (solve(n, i+1, false) + solve(n, i+1, true)) % MOD;
        
        return dp[i][prevGap] = (solve(n, i+1, false) + solve(n, i+2, false) + 2l*solve(n, i+2, true)) % MOD;
    }
    
    int numTilings(int n) {
        return solve(n, 0, false);
    }
};