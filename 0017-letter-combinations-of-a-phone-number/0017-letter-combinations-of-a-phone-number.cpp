class Solution {
private:
    void solve(string digits, string output, int index, vector<string>& ans, string mapping[]) {
        // Base case
        if(index>=digits.length()) {
            ans.push_back(output);
            return;
        }
        
        // get the number
        int number = digits[index]-'0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, mapping);
            output.pop_back();
        }   
        
    }
public:
    vector<string> letterCombinations(string digits) {
        // create an ans vector of type string
        vector<string> ans;
        
        // If input length is 0, return empty string
        if(digits.length() == 0){
            return ans;
        }
        
        // output string
        string output = "";
        int index = 0;
        
        // mapping of digits to letters
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};