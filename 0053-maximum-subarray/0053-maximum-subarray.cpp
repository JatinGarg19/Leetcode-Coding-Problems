class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // This solution is based on Kadane's Algorithm
        int sum = 0;
        int maximum_sum =  INT_MIN;      // TC - O(N), SC - O(1)

        for(auto i : nums) {
            sum += i;
            maximum_sum = max(maximum_sum, sum);
            // if at any point, sum becomes -ve, make it 0 again.
            if(sum < 0) sum = 0;
        }
        // At the end, we will get the subarray with max sum and return that max sum.
        return maximum_sum;
    }
};