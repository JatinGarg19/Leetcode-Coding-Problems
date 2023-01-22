class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    int fn(int idx, string &s, int n, vector<int> &dp) {
        // Base Case
        if(idx == n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int minCuts = 1e9;
        
        for(int j = idx; j < n; j++) {
            if(isPalindrome(idx, j, s)) {
                int cut = 1 + fn(j + 1, s, n, dp);
                minCuts = min(minCuts, cut);
            }
        }
        
        return dp[idx] = minCuts;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        // This func will return n partitions, and we need n - 1 as output
        return fn(0, s, n, dp) - 1;
    }
};