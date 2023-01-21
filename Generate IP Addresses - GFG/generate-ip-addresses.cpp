//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    vector<string> genIp(string &s) {
        vector<string> result;
        if(s.length() < 4) {
            result.push_back("-1");
            return result;
        }
        
        string ip;
        dfs(s, 0, 0, ip, result);
        return result;
    }
    
    void dfs(string &s, int start, int step, string ip, vector<string> &result) {
        
        if(start == s.size() and step == 4) {
            ip.erase(ip.end() - 1);
            result.push_back(ip);
            return;
        }
        
        if(s.size() - start > (4 - step) * 3)
            return;
        if(s.size() - start < (4 - step))
            return;
        
        int num = 0;
        for(int i = start; i < start + 3; i++) {
            num = num * 10 + (s[i] - '0');
            
            if(num <= 255) {
                ip = ip + s[i];
                dfs(s, i + 1, step + 1, ip + '.', result);
            }
            
            if(num == 0) break;
        }
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends