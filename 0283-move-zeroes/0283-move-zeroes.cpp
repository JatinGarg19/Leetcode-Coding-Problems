class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        // Iterate over the nums array
        for(int j=0; j<nums.size(); j++) {
            // If it is a non-zero element, swap with nums[i].
            if(nums[j] != 0) {
                swap(nums[j] , nums[i]);
                    i++;
            }
        }
    // return nums;
    }      // TC - O(N), SC - O(1).
};

/* DRY RUN -
IP = 0 1 0 3 12
1ST - 0 1 0 3 12
2ST - 1 0 0 3 12
3RD - 1 0 0 3 12
4TH - 1 3 0 0 12
5TH - 1 3 12 0 0 - ANS */
