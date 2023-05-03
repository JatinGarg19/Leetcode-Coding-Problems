class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans = {{} , {}};
        
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        for(auto x : s1) {
            if(s2.count(x) == 0) ans[0].push_back(x);
        }
        
        for(auto x : s2) {
            if(s1.count(x) == 0) ans[1].push_back(x);
        }
        
        return ans;
    }
};