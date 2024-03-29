class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        
        for(int i = 1; i <= n + 1; i++) {
            if(st.find(i) == st.end())
                return i;
        }
        
        return n + 1;
    }
};