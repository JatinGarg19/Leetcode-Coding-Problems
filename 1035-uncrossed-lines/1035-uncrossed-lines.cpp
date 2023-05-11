class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return solve(nums1, nums2, 0, 0, dp);
    }
    
    int solve(vector<int>& nums1, vector<int>& nums2, int id1, int id2, vector<vector<int>> &dp) {
        if(id1 == nums1.size() || id2 == nums2.size()) return 0;
        
        if(dp[id1][id2] != -1) return dp[id1][id2];
        
        if(nums1[id1] == nums2[id2]) {
            return dp[id1][id2] = 1 + solve(nums1, nums2, id1 + 1, id2 + 1, dp);
        }
        else {
            int x = solve(nums1, nums2, id1 + 1, id2, dp);
            int y = solve(nums1, nums2, id1, id2 + 1, dp);
            return dp[id1][id2] = max(x, y);
        }
        
    }
};