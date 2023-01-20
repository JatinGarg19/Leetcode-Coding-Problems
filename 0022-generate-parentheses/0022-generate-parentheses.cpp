class Solution {
public:
    void solve(vector<string> &result, string s, int open, int close, int n) {
        // if the count of both open and close parentheses
        // reaches n, it means we have generated a valid
        // parentheses. So, we add the currently generated string
        // s to the final ans and return
        if(close == n && open == n) {
            result.push_back(s);
            return;
        }

        // if count of open brackets is less than n
        if(open < n) solve(result, s + '(', open + 1, close, n);

        // if count of closed bracets is less than n.
        if(close < open) solve(result, s + ')', open, close + 1, n);
    } 

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(result, "", 0, 0, n);
        return result;                       // Time - O(2^n) Space - O(n).
    }
};