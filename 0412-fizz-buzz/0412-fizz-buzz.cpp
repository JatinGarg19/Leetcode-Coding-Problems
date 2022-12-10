class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // Declare an ans vector
        vector<string> ans;
        
        // run a loop from 1 to n included.
        for(int i = 1; i <= n; i++) {
            
            // If i is divisible by both 3 and 5, push FizzBuzz
            if(i % 3 == 0 and i % 5 == 0) {
                ans.push_back("FizzBuzz");
            }
            
            // If i is divisible by 3, push fizz
            else if(i % 3 == 0) {
                ans.push_back("Fizz");
            }
            
            // If i is divisble by 5, push buzz
            else if(i % 5 == 0) {
                ans.push_back("Buzz");
            }
            
            // else push i.
            else {
                ans.push_back(to_string(i));
            }
        }
        
        return ans;
    }
};