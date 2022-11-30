class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        // CREATE A HASHTABLE
        unordered_map<int, int> map;
        
        // ITERATE OVER NUMS ARRAY
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(target - nums[i]) != map.end()) {
                // IF FOUND, PUSH INDEX TO ANS
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            // IF NOT EQUAL TO TARGET, PUSH ELEMENT TO TABLE
            map[nums[i]] = i;
        }
        return ans;
    }
};