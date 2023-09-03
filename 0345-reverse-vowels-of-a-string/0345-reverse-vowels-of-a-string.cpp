class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        stack<char> st;
        
        for(char c : s) {
            if(vowels.contains(c)) st.push(c);
        }
        
        for(char &c : s) {
            if(vowels.contains(c)) {
                c = st.top();
                st.pop();
            }
        }
        
        return s;
    }
};