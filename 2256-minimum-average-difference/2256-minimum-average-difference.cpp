class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long totalSum = 0, currSum = 0;
        int n = nums.size();
        
        // Calculate Total Sum of the array
        for(auto i : nums) {
            totalSum += i;
        }
        
        int mini = INT_MAX;
        int idxAns = 0;
        
        // calculate the avg1 till ith idx and avg2 till n-i-1 idx.
        // now take abs diff of avg1 and avg2 and keep tracking the idx giving minimum diff
        // return the idx giving minimum difference.
        for(int i = 0; i < n; i++) {
            currSum += nums[i];
            int avg1 = currSum / (i + 1);
            
            if(i == n - 1) {
                if(avg1 < mini) {
                    return n - 1;
                }
                else {
                    break;
                }
            }
            
            int avg2 = (totalSum - currSum) / (n - i - 1);
            
            if(abs(avg1 - avg2) < mini) {
                mini = abs(avg1 - avg2);
                idxAns = i;
            }
        }
        
        return idxAns;
    }
};