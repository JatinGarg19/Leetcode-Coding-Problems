class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        for(int i = 0; i < n; i++) {
            int j = 0, ind = i;
            
            while(j < m and haystack[ind] == needle[j]) {
                j++;
                ind++;
            }
            
            if(j == m) return i;
        }
        
        return -1;
    }
};