class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        
        int minsal = INT_MAX;
        int maxsal = INT_MIN;
        
        double totalsum = 0;
        
        for(int i = 0; i < n; i++) {
            totalsum += salary[i];
        }
        
        for(int i = 0; i < n; i++) {
            minsal = min(minsal, salary[i]);
            maxsal = max(maxsal, salary[i]);
        }
        
        double avgsal = (totalsum - minsal - maxsal) / (n - 2);
        
        return avgsal;
    }
};