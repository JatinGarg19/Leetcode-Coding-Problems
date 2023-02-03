class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        vector<string> stack(numRows, "");
        
        int period = (numRows - 1) * 2;
        
        for(int i = 0; i < s.size(); i++) {
            int curr = i % period;
            
            if(curr >= numRows) {
                curr = period - curr;
            }
            stack[curr] += s[i];
        }
        
        string ans = "";
        for(int i = 0; i < numRows; i++) {
            ans += stack[i];
        }
        
        return ans;
    }
};