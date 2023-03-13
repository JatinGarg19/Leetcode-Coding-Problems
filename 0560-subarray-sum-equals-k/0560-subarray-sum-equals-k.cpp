class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // create a hashmap
        unordered_map<int,int> map;
        
        int sum = 0, count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if(sum == k) count++;
            
            if(map.find(sum - k) != map.end()) {
                count = map[sum - k] + count;
            }
            
            if(map.find(sum) != map.end()) {
                map[sum]++;
            } else {
                map[sum] = 1;
            }
        }
        
        return count;
    }
};