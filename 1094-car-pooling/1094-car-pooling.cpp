class Solution {
public:
    // This problem is very similar to the hotel bookings possible problem
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<pair<int,int>> v;
        
        for(int i=0; i<n; i++) {
            // Push to vector from loc and numPassengersi
            v.push_back(make_pair(trips[i][1], trips[i][0]));
            // Push to vector to loc and numPassengersi
            v.push_back(make_pair(trips[i][2], -trips[i][0]));  
        }
        // Sort the vector
        sort(v.begin(), v.end());
        
        int var = 0;
        for(int i = 0; i < v.size(); i++) {
            var += v[i].second;
            if(var > capacity) return false;
        }
        
        return true;       // TC - O(NlogN), SC-O(N).
    }
};