//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        int maxStrSum = INT_MIN;
        int minStrSum = INT_MAX;
        int arrSum = 0;
        
        int tmpMaxSum = 0;
        int tmpMinSum = 0;
        
        for(int i = 0; i < num; i++) {
            arrSum += arr[i];
            
            tmpMaxSum += arr[i];
            maxStrSum = (maxStrSum < tmpMaxSum) ? tmpMaxSum : maxStrSum;
            tmpMaxSum = (tmpMaxSum < 0) ? 0 : tmpMaxSum;
            
            tmpMinSum += arr[i];
            minStrSum = (minStrSum > tmpMinSum) ? tmpMinSum : minStrSum;
            tmpMinSum = (tmpMinSum > 0) ? 0 : tmpMinSum;
        }
        
        if(arrSum == minStrSum) {
            return maxStrSum;
        }
        
        return max(maxStrSum, (arrSum - minStrSum));
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends