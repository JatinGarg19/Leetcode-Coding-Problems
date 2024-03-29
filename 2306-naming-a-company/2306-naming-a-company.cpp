class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long count = 0;
        
        vector<unordered_set<string>> arr(26);
        
        for(string s : ideas) {
            arr[s[0] - 'a'].insert(s.substr(1));
        }
        
        for(int i = 0; i < 25; i++) {
            for(int j = i + 1; j < 26; j++) {
                unordered_set<string> st;
                
                st.insert(arr[i].begin() , arr[i].end());
                st.insert(arr[j].begin() , arr[j].end());
                
                count += (arr[i].size() - st.size()) * (arr[j].size() - st.size());
            }
        }
        
        return count * 2;
    }
};