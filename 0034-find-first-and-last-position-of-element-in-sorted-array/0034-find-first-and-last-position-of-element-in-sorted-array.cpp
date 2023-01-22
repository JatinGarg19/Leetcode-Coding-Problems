class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            // If target is not equal to array element, move ahead.
            if(target != nums[i]) 
                continue;
            
            // If target is equal and it is its first occurence.
            if(first == -1) 
                first = i;
            
            // always update last with idx whether its first occurence or second.
            last = i;
        }
        
        return {first, last};
    }
};