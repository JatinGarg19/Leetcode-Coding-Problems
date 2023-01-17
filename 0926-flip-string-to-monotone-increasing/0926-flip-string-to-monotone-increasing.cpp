class Solution {
public:
    int minFlipsMonoIncr(string s) {
        return solve(s); 
    }
    
    int solve(string &s) {
        // Maintain a zeroCount and a oneCount 
        int flips = 0;
        int counter = 0;
        
        for(auto it : s) {
            // If the char is '1', increment counter
            if(it == '1')
                counter++;
            // If the char is '0', increment flips
            else 
                flips++;
            
            // To maintain the count of zeroes after the 1 only, minimize the value of flips
            flips = min(flips, counter);
        }
        
        // return flips.
        return flips;
    }
};