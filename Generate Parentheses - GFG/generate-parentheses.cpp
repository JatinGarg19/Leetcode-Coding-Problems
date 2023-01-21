//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    vector<string> ans;
    
    public:
    void dfs(int n, string s, int left, int right) {
        // At any step, lc and rc should not exceed n and rc should not be > than lc
        if(left > n || right > n || right-left > 0) 
            return;
        
        // This is the required condition
        if(left == right && left == n) {
            ans.push_back(s);
            return;
        }
        
        // check if we can still add left parenthesis
        if(left < n) {
            dfs(n, s + '(', left + 1, right);
        }
        
        // checkif we can still add right parenthesis
        if(right < n) {
            dfs(n, s + ')', left, right + 1);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // dfs(n, empty string, leftcount, rightcount)
        dfs(n, "", 0, 0);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends