class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxL = 0;
        // left for '(' and right for ')' count
        int left = 0, right = 0;
        
        // Scan from left to right
        for(int i = 0; i < n; i++) {
            // opening bracket - increment left
            if(s[i] == '(')
                left++;
            // closing bracket - increment right
            else 
                right++;
            
            // reset l and r if r > l.
            if(right > left)
                left = right = 0;
            // if equal, update maxL.
            else if(left == right)
                maxL = max(maxL, 2*right);
        }
        
        // reset both l and r to 0.
        left = right = 0;
        
        // Scan from right to left - to handle cases if count of '(' is more than ')'.
        for(int i = n - 1; i >= 0; i--) {
            // same as above.
            if(s[i] == '(')
                left++;
            else 
                right++;
            
            // if l > r, reset to 0.
            if(left > right)
                left = right = 0;
            // if equal , update maxL.
            else if(left == right)
                maxL = max(maxL, 2*left);
        }
        
        // return the final maxL
        return maxL;
    }
};