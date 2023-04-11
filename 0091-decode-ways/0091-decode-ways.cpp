class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1, -1);
        return countDecodings(s, 0, dp);
    }
    
    int countDecodings(string s, int idx, vector<int>& dp) {
        if(idx == s.length()) return 1;
        
        int count = 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        if(s[idx] != '0') count += countDecodings(s, idx+1, dp);
        
        if(idx+1 < s.length() && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6'))) {
            count += countDecodings(s, idx+2, dp);
        }
        
        return dp[idx] = count;
    }
};