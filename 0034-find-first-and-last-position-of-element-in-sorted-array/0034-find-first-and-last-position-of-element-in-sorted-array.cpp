class Solution {
public:
    int first(vector<int>& nums, int low, int high, int x) {
        int result = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > x) 
                high = mid - 1;
            
            else if(nums[mid] < x)
                low = mid + 1;
            
            else {
                result = mid;
                high = mid - 1;
            }
        }
        
        return result;
    }
    
    int last(vector<int>& nums, int low, int high, int x) {
        int result = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > x) 
                high = mid - 1;
            
            else if(nums[mid] < x)
                low = mid + 1;
            
            else {
                result = mid;
                low = mid + 1;
            }
        }
        
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOc = first(nums, 0, nums.size() - 1, target);
        int lastOc = last(nums, 0, nums.size() - 1, target);
        
        return {firstOc, lastOc};
    }
};