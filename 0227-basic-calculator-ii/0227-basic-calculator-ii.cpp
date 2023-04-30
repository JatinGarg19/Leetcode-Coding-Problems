class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        
        if(len == 0) return 0;
        
        stack<int> st;
        char operation = '+';
        int currNumber = 0;
        
        for(int i = 0; i < len; i++) {
            char currChar = s[i];
            if(isdigit(currChar)) {
                currNumber = (currNumber * 10) + (currChar - '0');
            }
            
            if(!isdigit(currChar) && !iswspace(currChar) || i == len-1) {
                if(operation == '-')
                    st.push(-currNumber);
                else if(operation == '+')
                    st.push(currNumber);
                else if(operation == '*') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop * currNumber);
                }
                else if(operation == '/') {
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop / currNumber);
                }
                
                operation = currChar;
                currNumber = 0;
            }
        }
        
        int ans = 0;
        while(st.size() != 0) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};