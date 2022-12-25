class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Intialize the sum of 1st 3 elements as the closest sum.
        int closestSum = nums[1] + nums[2] + nums[3];
        
        // sort the array
        sort(nums.begin(), nums.end());
        
        // Iterate through the array.
        for(int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;  // left pointer
            int right = nums.size() - 1;   // right pointer
            
            // Move the pointers to find the sum closest to the target value.
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];  // current sum
                
                if(abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;  // update closestSum
                }
                if(sum < target) {
                    left++;
                }
                else if(sum > target) {
                    right--;
                }
                else {
                    return sum;  // sum = target, return sum.
                }
            }
        }
        
        return closestSum;
    }
};