class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans = 0;
        for(int i = 0; i < rocks.size(); i++) {
            rocks[i] = capacity[i] - rocks[i];
        }
        
        sort(rocks.begin(), rocks.end());
        
        for(auto it : rocks) {
            if(it > 0 && additionalRocks >= it) {
                ans++;
                additionalRocks -= it;
            }
            else if(it == 0) {
                ans++;
            }
            else {
                break;
            }
        }
        
        return ans;     // TC - O(N) + O(logN) + O(N) , SC - O(1).
    }
};