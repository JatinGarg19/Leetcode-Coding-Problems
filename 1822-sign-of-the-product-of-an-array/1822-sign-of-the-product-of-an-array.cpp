class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) return 0;
            if(nums[i] < 0) count++;
        }
        
        // if (count % 2) returns 0, 1 is the answer, if it returns 1, -1 is the ans.
        return (count % 2) ? -1 : 1;
    }
};