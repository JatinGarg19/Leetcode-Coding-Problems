class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> hmap;
        
        for (int idx = 0; idx < s.size(); idx++) {
            // Everytime the character appears in the string, add one to its count
            hmap[s[idx]]++;
        }
        
        // Traverse the string from the beginning...
        for (int idx = 0; idx < s.size(); idx++) {
            // If the count of the char is equal to 1, it is the first distinct                               character in the list.
            if (hmap[s[idx]] == 1)
                return idx;
        }
        
        return -1;  
    }
};