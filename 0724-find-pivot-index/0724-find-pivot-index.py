class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        leftsum = 0
        
        total = sum(nums)
        
        for j in range(len(nums)):
            total -= nums[j]
            if(leftsum == total):
                return j
            else:
                leftsum += nums[j]
        
        return -1;
        