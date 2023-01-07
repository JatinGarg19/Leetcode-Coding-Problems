class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int curFuel = 0, start = 0;  // In beginning, we have start = 0 and curfuel = 0
        int totalGas = 0, totalcost = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];   // Calculate totalfuel
        }  
        
        for(int i = 0; i < cost.size(); i++) {
            totalcost += cost[i];   // Calculate totalcost
        }
        
        // If what we have is less than what we need, then return -1.
        if(totalGas < totalcost) {
            return -1;
        }
        
        for(int i = 0; i < gas.size(); i++) {
            curFuel += (gas[i] - cost[i]);
            if(curFuel < 0) {   // at any idx, curfuel becomes -ve, update curfuel to 0 and start to i+1
                start = i + 1;
                curFuel = 0;
            }
        }
        
        return start;      // TC - O(N) + O(N) + O(N) ~~ O(N).    SC - O(1)
    }
};