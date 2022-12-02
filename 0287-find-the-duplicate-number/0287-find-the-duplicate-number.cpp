class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // INTIALIZE SLOW AND FAST POINTERS
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        // INITIALIZE FAST TO 0TH INDEX AGAIN
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};