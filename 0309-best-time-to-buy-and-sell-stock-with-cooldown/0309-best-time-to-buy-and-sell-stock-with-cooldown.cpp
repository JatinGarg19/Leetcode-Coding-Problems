class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(prices, 1, 0, dp);
    }

    int f(vector<int>& prices, int buy, int idx, vector<vector<int>>& dp) {
        if(idx >= prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;

        if(buy) {
            profit = max(-prices[idx] + f(prices, 0, idx + 1, dp), 0 + f(prices, 1, idx + 1, dp));
        }
        else {
            profit = max(prices[idx] + f(prices, 1, idx + 2, dp), 0 + f(prices, 0, idx + 1, dp));
        }

        return dp[idx][buy] = profit;
    }
};