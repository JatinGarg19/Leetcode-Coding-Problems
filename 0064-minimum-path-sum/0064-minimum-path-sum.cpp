class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        int ans = func(grid, 0, 0, m, n, dp);
        return ans;
    }
    
    int func(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(i >= m || j >= n)
            return INT_MAX;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == m - 1 && j == n - 1)
            return grid[i][j];
        
        int rightSum = func(grid, i, j + 1, m, n, dp);
        int downSum = func(grid, i + 1, j, m, n, dp);
        int minSum = min(rightSum, downSum);
        
        return dp[i][j] = grid[i][j] + minSum;  // Tc - O(2^(m+n)) , Sc - O(m+n).
    }
};