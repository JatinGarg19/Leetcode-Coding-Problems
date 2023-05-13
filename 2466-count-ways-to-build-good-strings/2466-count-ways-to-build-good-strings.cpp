

class Solution {
public:
    int mod = 1e9 + 7;
    
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        
        vector<int> dp(high + 1, -1);
        
        for(int i = low; i <= high; i++) {
            ans = (ans + (getCount(zero, one, i, dp)) % mod) % mod;
        }
        
        return ans;
    }
    
    int getCount(int zero, int one, int n, vector<int> &dp) {
        int count = 0;
        
        if(n == 0) return 1;
        
        if(n < 0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (getCount(zero, one, n - zero, dp) % mod + getCount(zero, one, n - one, dp) % mod) % mod;
            
    }
};