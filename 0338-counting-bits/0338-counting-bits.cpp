class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        
        for(int i = 0; i <= n; i++) {
            int count = 0, num = i;
            while(num > 0) {
                if(num & 1) {
                    count++;
                }
                num = num >> 1;
            }
            ans[i] = count;
        }
        
        return ans;
    }
};