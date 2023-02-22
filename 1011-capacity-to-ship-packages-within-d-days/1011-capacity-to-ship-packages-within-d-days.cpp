class Solution {
public:
    // Function to check if the weights can be delivered in d days or not.
    bool isValid(vector<int> &weights, int n, int days, int mx) {
        
        // Stores the count of days required to ship all the weights if the maximum capacity is mx.
        int st = 1;
        int sum = 0;
        
        // Traverse all the weights.
        for(int i = 0; i < n; i++) {
            sum += weights[i];
            
            // If total weight is more than the maximum capacity.
            if(sum > mx) {
                st++;
                sum = weights[i];
            }
            
            // If days are more than D(days) , return false.
            if(st > days) {
                return false;
            }
        }
        
        // return true if days > D(days).
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        // Array size.
        int n = weights.size();
        
        // stores the total weights to be shipped.
        int sum = 0;
        
        // Sum of weights.
        for(int i = 0; i < n; i++) {
            sum += weights[i];
        }
        
        // Stores the max weight in the array that has to be shipped.
        int s = weights[0];
        for(int i = 1; i < n; i++) {
            s = max(s , weights[i]);
        }
        
        // Store the ending value of the search space.
        int e = sum;
        
        // stores the required result.
        int result = -1;
        
        // Perform the binary search.
        while(s <= e) {
            // Store the middle value.
            int mid = s + (e - s) / 2;
            
            // If mid can be shipped , then update the result and end value of the search space.
            if(isValid(weights, n, days, mid)) {
                result = mid;
                e = mid - 1; 
            }
            
            // Search for minimum value in the right part.
            else {
                s = mid + 1;
            }
        }
        
        // return the result.
        return result;
    }
};