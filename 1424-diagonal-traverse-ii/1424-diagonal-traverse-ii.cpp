class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        unordered_map<int,vector<int>> m;
        int max_key = 0; // MAX KEY INSERTED INTO THE MAP i.e MAX VALUE OF I + J INDICES.
        
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                m[i+j].push_back(nums[i][j]); // insert nums[i][j] in bucket (i+j).
                max_key = max(max_key, i+j);
            }
        }
        
        for(int i=0; i<= max_key; i++) {          // Each diagonal starting with sum 0 to sum maxKey.
            for(auto x = m[i].rbegin(); x != m[i].rend(); x++) {          // print in reverse order.
                ans.push_back(*x); 
            }
        }
        
        return ans;
    }
};