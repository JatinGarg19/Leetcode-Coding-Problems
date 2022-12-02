class Solution {
public:
    // If two strings are close -
    // they must have same set of characters
    // freq of each char in each string must be same
    
    bool closeStrings(string word1, string word2) {
        // base case
        if(word1.length() != word2.length()) return false;
        
        // Create two vectors of size 26 and initialize with 0.
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        
        // count the number of each char in word1 and incerement corresponding idx in v1
        for(char ch : word1) v1[ch - 'a']++;
        
        // count the number of each char in word2 and incerement corresponding idx in v2
        for(char ch : word2) v2[ch - 'a']++;
        
        // check if there is a char in word1 and not in word2 or vice - versa.
        for(int i = 0; i < 26; i++) {
            if((v1[i]==0 and v2[i]!=0) or (v1[i]!=0 and v2[i]==0)) return false;
        }
        
        // sort both the vectors
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        // return true if both the vectors are equal, else return false;
        return v1 == v2;
    }
};