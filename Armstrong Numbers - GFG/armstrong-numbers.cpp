//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        int originalNo = n;
        int count = 0;
        int temp = n;
        
        while(temp != 0) {
            count++;
            temp = temp/10;
        }
        
        int sumOfPower = 0;
        while(n != 0) {
            int digit = n % 10;
            sumOfPower += pow(digit, count);
            n /= 10;
        }
        
        return (sumOfPower == originalNo) ? "Yes" : "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends