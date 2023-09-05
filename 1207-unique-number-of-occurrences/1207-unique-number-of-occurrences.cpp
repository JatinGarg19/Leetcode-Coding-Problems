class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> count;
        
        set<int> st;
        
        for(int i=0; i<arr.size(); i++) {
            count[arr[i]]++;
        }
        
        for(auto it : count) {
            st.insert(it.second);
        }
        
        return (count.size() == st.size()) ? 1 : 0;
    }
};