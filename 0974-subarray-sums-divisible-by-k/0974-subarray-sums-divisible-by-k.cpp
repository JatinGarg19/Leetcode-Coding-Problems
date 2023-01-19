class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 0) return 0;
        
        int i = 0, count = 0;
        int curSum = 0;
        
        unordered_map<int,int> mp;
        // This os done because initial sum = 0 and sum%k = 0 always
        mp[0] = 1;
        
        while(i < n) {
            curSum += nums[i++];
            int rem = curSum % k;
            
            if(rem < 0) rem += k;
            
            if(mp.find(rem) != mp.end()) {
                count +=  mp[rem];
            }
            
            mp[rem]++;
        }
        
        return count;
    }
};