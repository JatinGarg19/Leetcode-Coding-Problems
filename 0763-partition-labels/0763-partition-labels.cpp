class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char , int> m;
        
        for(int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
        }
        
        vector<int> ans;
        
        int start = 0;
        int last = 0;
        
        for(int curr = 0; curr < s.size(); curr++) {
            last = max(last , m[s[curr]]);
            
            if(curr == last) {
                ans.push_back(last - start + 1);
                start = curr + 1;
            }
        }
        
        return ans;   // TC - O(N) (length of the string) 
    }  // SC - O(1) , although we have declared a map , its size is limited to 26 ,
      //   so constant space.
};