class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int value1, value2;
        stack<int> st;
        
        for(string i : operations) {
            if(i == "C") {
                st.pop();
            }
            else if(i == "D") {
                st.push(st.top() * 2);
            }
            else if(i == "+") {
                value1 = st.top(); st.pop();
                value2 = st.top();
                int newValue = value1 + value2;
                st.push(value1);
                st.push(newValue);
            }
            else {
                // convert string to integer and push to stack
                st.push(stoi(i));
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