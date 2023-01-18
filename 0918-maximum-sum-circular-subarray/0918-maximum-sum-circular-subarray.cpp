class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int maxStrSum = INT_MIN;
        int minStrSum = INT_MAX;
        int arrSum = 0;
        
        int tmpMaxSum = 0;
        int tmpMinSum = 0;
        
        for(int i = 0; i < n; i++) {
            arrSum += nums[i];
            
            tmpMaxSum += nums[i];
            maxStrSum = (maxStrSum < tmpMaxSum) ? tmpMaxSum : maxStrSum;
            tmpMaxSum = (tmpMaxSum < 0) ? 0 : tmpMaxSum;
            
            tmpMinSum += nums[i];
            minStrSum = (minStrSum > tmpMinSum) ? tmpMinSum : minStrSum;
            tmpMinSum = (tmpMinSum > 0) ? 0 : tmpMinSum;
        }
        
        if(arrSum == minStrSum) {
            return maxStrSum;
        }
        
        return max(maxStrSum, (arrSum - minStrSum));
    }
};