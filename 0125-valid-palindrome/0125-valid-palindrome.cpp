class Solution {
public:
    
    bool helper(string a) {
        int i = 0, j = a.size()-1;
        while(i < j) {
            if(a[i] != a[j]) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
}
    
    bool isPalindrome(string s) {
        string x = "";
        for(int i=0; i<s.size(); i++){
            if(isalpha(s[i]))
            {
                x += s[i];
            }
            else if(isdigit(s[i])) {
                x += s[i]; 
            }
        }

        for(int i=0; i<x.size(); i++) {
            x[i] = tolower(x[i]);
        }

        if(helper(x) == true) {
            return 1;
        }
        else {
            return 0;
        }

        
    }
};