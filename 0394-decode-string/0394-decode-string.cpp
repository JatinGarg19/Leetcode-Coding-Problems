class Solution {   
public:
    string decodeString(string s) {
        int pos = 0;
        return solve(s , pos);
    }
    
    string solve(string s, int &pos) {
        int num = 0;
        string ans = "";
        
        for( ; pos < s.size(); pos++) {
            char curr = s[pos];
            
            if(curr == '[') {
                string currStr = solve(s , ++pos);
                
                for( ; num > 0; num--)
                    ans += currStr;
            }
            
            else if(curr >= '0' && curr <= '9') {
                num = (num * 10) + curr - '0';
            }
            else if(curr == ']')
                return ans;
            else
                ans += curr;
        }
        
        return ans;
    }
};