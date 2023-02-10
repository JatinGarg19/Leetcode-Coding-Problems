// define an unordered set operations
static unordered_set<string> operations({"+" , "-" , "*" , "/"});

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // declare a stack.
        stack<int> st;
        
        for(auto t : tokens) {
            // if the incoming character is a number , push onto stack.
            if(operations.find(t) == operations.end()) {
                st.push(stoi(t));
            }
            
            // if the incoming character is a operator , evaluate the expression.
            else {
                int b = st.top();
                st.pop();
                
                int a = st.top();
                st.pop();
                
                // Evaluate and push to stack.
                if(t == "+") st.push(a + b);
                else if(t == "-") st.push(a - b);
                else if(t == "*") st.push(a * b);
                else st.push(a / b);
            }
        }
        
        return st.top();
    }
};