class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0 , j = 1;
        
        while(i < n && j < n) {
            // Even element at even index.
            if(nums[i] % 2 == 0)
                i += 2;
            
            // Odd element at odd index.
            else if(nums[j] % 2 == 1)
                j += 2;
            
            // Either even element at odd idx or odd element at even idx.
            else 
                swap(nums[i] , nums[j]);
        }
        
        return nums;
    }
};