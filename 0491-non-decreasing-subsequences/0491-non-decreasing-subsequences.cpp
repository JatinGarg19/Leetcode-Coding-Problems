class Solution {
    vector<vector<int>> ans;
    
public:
    void dfs(vector<int> &temp, vector<int> &nums, int idx) {
        // Base Condition
        if(temp.size() > 1) ans.push_back(temp);
        
        // for each dfs, declare unordered set
        unordered_set<int> set;
        
        for(int i = idx; i < nums.size(); i++) {
            // condition
            if((temp.size() == 0 || temp.back() <= nums[i]) && set.find(nums[i]) == set.end()) {
                temp.push_back(nums[i]);
                dfs(temp, nums, i + 1);
                temp.pop_back();
                set.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        dfs(temp, nums, 0);
        return ans;
    }
};