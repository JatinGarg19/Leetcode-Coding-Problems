class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // TC - ~O(N) , SC - O(1)
        
        
        int carry = 1;
        // Check for last element
        for(int i=digits.size()-1; i>0; i--) {
            // If last element becomes 10, then make that digit 0 and push 1 to carry
            if(digits[i] + carry == 10) {
                digits[i] = 0;
                carry = 1;
            }
            // Else simply add the digit with 1 and move carry as 0.
            else {
                digits[i] = digits[i] + carry;
                carry = 0;
            }
        }

        // Check for 1st element
        // If 1st elem becomes 10, make that digit 0 and insert 1 before it.
        if(digits[0] + carry == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        // Else add that no and remove leading zeroes if any from the start.
        else {
            digits[0] = digits[0] + carry;
            while(digits[0] == 0) {
                digits.erase(digits.begin());
            }
        }

        return digits;
    }
};