class Solution {
public:
    int f(int i, int j, vector<vector<int>> &dp) {
        // We have reached our destination.
        if(i == 0 and j == 0) return 1;
        
        // Return 0 if we have gone out of bounds.
        if(j < 0 || i < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        // We are considering the reverse case here. Either we will go up or left.
        int up = f(i - 1, j, dp);
        int left = f(i, j - 1, dp);
        
        // return total unique paths.
        return dp[i][j] = up + left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, dp);
    }
};