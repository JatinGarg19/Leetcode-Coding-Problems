class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, vector<int>> index_values;
        
        // MAP THE ARRAY VALUE WITH CORRESPONDING INDEX.
        for(int i = 0; i < n; i++) {
            index_values[arr[i]].push_back(i);
        }
        
        // CREATE A BOOLEAN VECTOR VISITED WITH INDEX 0 AS TRUE AS IT IS THE FIRST NODE. 
        vector<bool> visited(n); visited[0] = true;
        
        // Create a queue and push 0 to queue.
        queue<int> q; q.push(0);
        
        // Required minimum number of steps.
        int steps = 0;
        
        while(!q.empty()) {
            for(int size = q.size(); size > 0; --size){
                int i = q.front(); q.pop();
                // We have reached the last index.
                if(i == n - 1) return steps;
                
                vector<int>& next = index_values[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                
                for(int j : next) {
                    if(j >= 0 and j < n and !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                
                // Avoid later lookup index_values[[arr[i]].
                index_values[arr[i]].clear();
            }
            
            steps++;
        }
        
        return 0;
    }
};