class Solution {
    public boolean increasingTriplet(int[] nums) {
        int n = nums.length;
        // Size of array is smaller than 3, so triplet not possible.
        if(n < 3) return false;
        
        int left = Integer.MAX_VALUE;
        int mid = Integer.MAX_VALUE;
        
        for(int i = 0; i < n; i++) {
            // if nums[i]>mid, nums[i] is also > than left, means we have two elements smaller
            // than nums[i], so it satisfies triplet and we return true. 
            if(nums[i] > mid) return true;
            
            //if nums[i] is greater than left and less than mid then it is clear that we find b in a               < b < c because it is quite possible that c can be INT_MAX.
            else if(nums[i]>left && nums[i]<mid) {
                mid = nums[i];
            }
            
            // if nums[i] < left, we update left to nums[i].
            else if(nums[i]<left) {
                left = nums[i];
            }
        }
        // if no triplet found, we return false.
        return false;   
    }
}
    