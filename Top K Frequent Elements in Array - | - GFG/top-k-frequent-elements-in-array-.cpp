//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        for(int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }
        
        for(auto &i : counts) {
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        vector<int> result;
        while(k--) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        reverse(result.begin(),result.end());
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends