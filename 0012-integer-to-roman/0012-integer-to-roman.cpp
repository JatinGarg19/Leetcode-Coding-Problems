class Solution {
public:
    
    string solve(int num) {
        vector<string> roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        vector<int> value = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        
        int seqSize = roman.size();
        int idx = seqSize - 1;
        string ans = "";
        
        while(num > 0) {
            while(value[idx] <= num) {
                ans += roman[idx];
                num -= value[idx];
            }
            idx--;
        }
        
        return ans;
    }
    
    string intToRoman(int num) {
        return solve(num);
    }
};