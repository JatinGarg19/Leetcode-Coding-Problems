class Solution {
public:
    vector<vector<string>> partition(string s) {
        // ans string
        vector<vector<string>> res;
        // temporary string to store the path
        vector<string> path;
        
        // function call
        func(0, s, path, res);
        return res;
    }
    
    void func(int ind, string s, vector<string>& path, vector<vector<string>>& res) {
        // Base Case
        if(ind == s.size()){
            // store the temporary string into the answer vector
            res.push_back(path);
            return;
        }
        
        for(int i=ind; i<s.size(); ++i) {
            // check if the substring is a palindrome or not
            if(isPalindrome(s, ind, i)) {
                path.push_back(s.substr(ind, i-ind+1));
                func(i+1, s, path, res);
                path.pop_back();
            }
        }
    }
    
    // function to check for palindrome
    bool isPalindrome(string s, int start, int end) {
        while(start <= end) {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    
};