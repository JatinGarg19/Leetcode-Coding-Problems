class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // We followed the 2 pointer approach. We first moved the val element to the right and returned i.
        int i = 0;
        for(int j = 0; j < nums.size(); j++) {
            if(nums[j] != val) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
        
        return i;
    }
};