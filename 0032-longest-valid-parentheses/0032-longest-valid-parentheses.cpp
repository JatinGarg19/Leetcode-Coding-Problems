class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxLength = 0;
        
        stack<int> stk; stk.push(-1);
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(')
                stk.push(i);
            else {
                stk.pop();
                if(stk.empty()) {
                    stk.push(i);
                } else {
                    maxLength = max(maxLength , i - stk.top());
                }
            }
        }
        
        return maxLength;   // Tc - O(n) , Sc - O(n).
    }
};