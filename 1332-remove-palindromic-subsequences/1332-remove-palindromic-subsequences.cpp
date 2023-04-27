class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0, j = s.size() - 1;
        
        bool isPalindrome = true;
        
        while(i <= j) {
            if(s[i] != s[j]) isPalindrome = false;
            i++;
            j--;
        }
        
        return (isPalindrome) ? 1 : 2;
    }
};