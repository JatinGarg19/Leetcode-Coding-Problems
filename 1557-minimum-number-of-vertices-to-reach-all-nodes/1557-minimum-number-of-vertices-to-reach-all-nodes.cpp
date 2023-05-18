class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result, reachable(n);
        
        for(auto &e : edges) {
            reachable[e[1]] = 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(reachable[i] == 0) {
                result.push_back(i);
            }
        }
        
        return result;      // Time - O(E) , Space - O(N).
    }
};