class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        
        // Iterate from 2nd last index to find 1st breakpoint.
        for(k = n - 2; k >= 0; k--) {
            if(nums[k] < nums[k + 1]) {
                break;
            }      
        }
        
        // If we do not find any breakpoint, we simply reverse to get the first permutation.
        if(k < 0) {
            reverse(nums.begin(), nums.end());
        }
        
        // If breakpoint found, check for number greater than beakpoint.
        else {
            for(l = n - 1; l > k; l--) {
                if(nums[l] > nums[k]) {
                    break;
                }
            }
            
            // Swap the indexes.
            swap(nums[k], nums[l]);
            // Reverse the remaining part to get the permutation.
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};