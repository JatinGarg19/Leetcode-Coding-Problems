class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 2;
        
        while(low <= high) {
            
            // RightShifting by twice means we are dividing it by 2.
            int mid = (low + high) >> 1;
            
            // If we do xor of mid with 1, it will give either prev element or next element
            if(nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
            
        }
        
        return nums[low];
    }
    
    /* In case of left half
     1st Instance - even index
     2nd instance - odd index, we need to check if 1st intance is there or not. */
    
};