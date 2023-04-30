class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        
        if(len == 0) return 0;
    
        char sign = '+'; int currNumber = 0, lastNumber = 0, result = 0;
        
        for(int i = 0; i < len; i++) {
            char currChar = s[i];
            if(isdigit(currChar)) {
                currNumber = (currNumber * 10) + (currChar - '0');
            }
            
            if(!isdigit(currChar) && !iswspace(currChar) || i == len-1) {
                if(sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currNumber : -currNumber;
                }
                    
                else if(sign == '*') {
                    lastNumber = lastNumber * currNumber;
                }
                
                else if(sign == '/') {
                    lastNumber = lastNumber / currNumber;
                }
                
                sign = currChar;
                currNumber = 0;
            }
        }
        
        result += lastNumber;
        
        return result;
    }
};