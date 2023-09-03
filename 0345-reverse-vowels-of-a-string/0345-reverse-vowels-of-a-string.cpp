class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int start = 0, end = s.size()-1;
        
        while(start < end) {
            while(start<end && !vowels.contains(s[start])) start++;
            
            while(start<end && !vowels.contains(s[end])) end--;
            
            swap(s[start], s[end]);
            
            start++;
            end--;
        }
        
        return s;
    }
};