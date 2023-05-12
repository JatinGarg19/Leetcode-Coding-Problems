class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, -1);
        return f(questions, 0, dp);
    }
    
    long long f(vector<vector<int>>& questions, int idx, vector<long long> &dp) {
        if(idx >= questions.size()) return 0;
        
        if(idx == questions.size() - 1) return questions[idx][0];
        
        if(dp[idx] != -1) return dp[idx];
        
        // select or ignore
        long long select = questions[idx][0] + f(questions, idx + 1 + questions[idx][1], dp);
        long long ignore = 0 + f(questions, idx + 1, dp);
        
        return dp[idx] = max(select, ignore);
    }
    
};