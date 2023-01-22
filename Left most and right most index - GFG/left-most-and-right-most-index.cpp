//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long first(vector<long long> &v, int low, int high, long long x, int n) {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            
            if ((mid == 0 || x > v[mid - 1]) && v[mid] == x)
                return mid;
            
            else if (x > v[mid])
                return first(v, (mid + 1), high, x, n);
            
            else
                return first(v, low, (mid - 1), x, n);
        }
        
        return -1;
    }
    
    long last(vector<long long> &v, int low, int high, long long x, int n) {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            
            if ((mid == n - 1 || x < v[mid + 1]) && v[mid] == x)
                return mid;
            
            else if (x < v[mid])
                return last(v, low, (mid - 1), x, n);
            
            else
                return last(v, (mid + 1), high, x, n);
        }
        
        return -1;
    }
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int n = v.size();
        long firstIdx = first(v, 0, n - 1, x, n);
        long lastIdx = last(v, 0, n - 1, x, n);
        
        return {firstIdx, lastIdx};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends