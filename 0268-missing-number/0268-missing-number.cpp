class Solution {
public:
    
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int arrSum = 0;
        
        int sumOfN = n*(n+1)/2;
        
        for(auto i : nums) {
            arrSum += i;
        }
        
        return (sumOfN - arrSum);
    }
};