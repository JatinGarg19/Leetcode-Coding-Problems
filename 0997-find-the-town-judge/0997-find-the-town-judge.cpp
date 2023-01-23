class Solution {
public:
    // Approach is to create a vector representing persons and increase the count of the person
    // who is trusted and decrease the count of person who trusts.
    // At the end, person with count == N - 1 will be the town judge.
    // It is also possible that there is no town judge.
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n + 1, 0);
        
        for(auto &t : trust) {
            degree[t[0]]--;
            degree[t[1]]++;
        }
        
        for(int i = 1; i <= n; i++) {
            if(degree[i] == n - 1) return i;
        }
        
        return -1;
    }
};