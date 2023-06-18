class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        
        return checkSubsequence(s, t, n - 1, m - 1);
    }
    
    bool checkSubsequence(string s, string t, int i, int j) {
        if(i == -1) return true;
        
        if(j == -1) return false;
        
        if(s[i] == t[j]) return checkSubsequence(s, t, i - 1, j - 1);
        
        return checkSubsequence(s, t, i, j - 1);
    }
};