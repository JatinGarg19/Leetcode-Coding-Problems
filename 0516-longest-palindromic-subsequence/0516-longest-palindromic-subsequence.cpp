class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
    
    int lcs(string &s, string &t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n-1, m-1, s, t, dp);
    }
    
    int f(int idx1, int idx2, string &s, string &t, vector<vector<int>>& dp) {
        if(idx1 < 0 || idx2 < 0) return 0;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(s[idx1] == t[idx2]) {
            return dp[idx1][idx2] = 1 + f(idx1-1, idx2-1, s, t, dp);
        }
        else {
           return dp[idx1][idx2] = 0 + max(f(idx1, idx2-1, s, t, dp), f(idx1-1, idx2, s, t, dp)); 
        }
    }
};