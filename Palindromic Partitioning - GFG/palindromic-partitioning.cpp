//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i, int j, string s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            
            i++;
            j--;
        }
        
        return true;
    }

    int f(int i, int n, string str, vector<int> &dp) {
        // BASE CASE
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int minCuts = 1e9;
        
        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j, str)) {
                int cuts = 1 + f(j + 1, n, str, dp);
                
                minCuts = min(minCuts, cuts);
            }
        }
        
        return dp[i] = minCuts;
    }

    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int> dp(n, -1);
        return f(0, n, str, dp) - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends