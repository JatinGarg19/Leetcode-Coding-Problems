class Solution {
public:
    static bool comparator(string a, string b) {
        return a + b > b + a; 
    }
    
    
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            s.push_back(to_string(nums[i]));
        }

        sort(s.begin(), s.end(), comparator);

        string ans = "";
        for(int i = 0; i < n; i++) {
            ans = ans + s[i];
        }

        if(s[0] == "0") return "0";

        return ans;    // Tc - O(n) + O(nlogn) + O(n) , Sc - O(n) approx
    }
};