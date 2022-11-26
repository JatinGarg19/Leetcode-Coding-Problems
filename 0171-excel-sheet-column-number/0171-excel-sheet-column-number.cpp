class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        reverse(columnTitle.begin(), columnTitle.end());
            
        for(int i=0; i<columnTitle.length(); i++) {
            int r;
            if(i == 0) {
                r = columnTitle[i] - 64;
            }
            else {
                r = (columnTitle[i] - 64) * pow(26,i);
            }
            
            ans = ans + r;
        }
        
        return ans;
    }
};