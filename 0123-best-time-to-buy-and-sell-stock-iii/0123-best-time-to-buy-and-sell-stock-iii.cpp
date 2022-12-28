class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp) {
        int n = prices.size();
        
        if(cap == 0) return 0;
        if(ind == n) return 0;
        
        int profit = 0;
        
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        // Can only Buy
        if(buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, cap, prices, dp), 
                             0 + f(ind + 1, 1, cap, prices, dp));
        }
        // You can only sell
        else {
            profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, dp),
                             0 + f(ind + 1, 0, cap, prices, dp));
        }
        
        return dp[ind][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    
                    // Can only Buy
                    if(buy) {
                        profit = max(-prices[ind] + dp[ind + 1][0][cap], 
                                        0 + dp[ind + 1][1][cap]);
                    }
                    // You can only sell
                    else {
                        profit = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                        0 + dp[ind + 1][0][cap]);
                    }
        
                    dp[ind][buy][cap] = profit;
                }
            } 
         }
        
        return dp[0][1][2];
    }
};