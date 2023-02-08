class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans = "";
        
        stack<char> st;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ']') {
                string temp;
                
                
                while(st.top() != '[') {
                    temp = st.top() + temp;
                    st.pop();
                }
                
                st.pop();
                
                string number = "";
                
                while(!st.empty() && isdigit(st.top())) {
                    number = st.top() + number;
                    st.pop();
                }
                
                int k = stoi(number);
                
                while(k--) {
                    for(int i = 0; i < temp.size(); i++) {
                        st.push(temp[i]);
                    }
                }
            }
            else {
                st.push(s[i]);
            }   
        }
        
        while(st.size() != 0) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};