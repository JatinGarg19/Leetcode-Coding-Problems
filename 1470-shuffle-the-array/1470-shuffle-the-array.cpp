class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        
        int ptr1 = 0;
        int ptr2 = n;
        
        while(ptr2 < 2*n) {
            result.push_back(nums[ptr1]);
            
            result.push_back(nums[ptr2]);
            
            ptr1++;
            ptr2++;
        }
        
        return result;
    }
};