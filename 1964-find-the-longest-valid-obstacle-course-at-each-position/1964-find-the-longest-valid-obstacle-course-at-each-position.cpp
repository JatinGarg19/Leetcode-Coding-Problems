class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // lis[i] stores the min. ending value of the longest inc. subsequence of length i
        vector<int> lis;
        
        for(int i = 0; i < obstacles.size(); ++i) {
            int x = obstacles[i];
            
            if(lis.empty() || lis[lis.size() - 1] <= x) {
                lis.push_back(x);
                obstacles[i] = lis.size();
            } else {
                 // Find the index of the smallest number > x
                int idx = upper_bound(lis.begin(), lis.end(), x) - lis.begin(); 
               
                lis[idx] = x; // Replace that number with x
                
                obstacles[i] = idx + 1;
            }
        }
        
        return obstacles;
    }
};