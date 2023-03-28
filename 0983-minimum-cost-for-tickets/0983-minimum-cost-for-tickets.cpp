class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int i, vector<bool>& map, vector<int>& dp) {
        if(i > 365) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        if(map[i] == false)
            return solve(days, costs, i + 1, map, dp);
        
        return dp[i] = min({costs[0] + solve(days, costs, i + 1, map, dp),
                   costs[1] + solve(days, costs, i + 7, map, dp),
                   costs[2] + solve(days, costs, i + 30, map, dp)});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> map(366, false);
        
        vector<int> dp(366, -1);
        
        for(auto i : days) 
            map[i] = true;
        
        int cost = solve(days, costs, 0, map, dp);
        
        return cost;
    }
};