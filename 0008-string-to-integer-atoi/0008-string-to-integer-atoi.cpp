class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
	    int i = 0;
        int ans = 0;
        
        if(s.length() == 0)
		    return 0;
        
        // Ignore the white-space if any.
        while(i<s.size() && s[i] == ' ') {
                i++;
        }
        
        // Take care of the final sign in the output.
	    if(s[i] == '-' || s[i] == '+') {
		    sign = (s[i] == '-') ? -1 : 1;
		    i++;
	    }
        
	    while(i<s.length() and (s[i]>='0' and s[i]<='9')) {
            int digit = (s[i]-'0')*sign;
            if(sign==1 and (ans>INT_MAX/10 || ans==INT_MAX/10 && digit>INT_MAX%10))
                return INT_MAX;
            if(sign==-1 and (ans<INT_MIN/10 || ans==INT_MIN/10 && digit<INT_MIN%10))
                return INT_MIN;
            
            ans = ans*10 + digit;
            i++;
        }
	
        return ans;
    }
};