class Solution {
public:
    
    /* n = 8
       bit rep of 7 = 0000 0111
       bit rep of 8 = 0000 1000
       bit rep of 7 & 8 = 0000 0000
       This means 8 is a power of two.
    */
    
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        return ((n & (n-1)) == 0);  // TC,SC = O(1).
    }
};