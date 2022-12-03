class Solution {
public:
    string frequencySort(string s) {
        // declare map for storing the frequency of each char in string
        map<char,int> m;
        for(auto it : s) {
            m[it]++;
        }
        
        // declare a max heap for sorting the map values based on frequency
        priority_queue<pair<int,char>> pq;
        for(auto i : m) {
            pq.push({i.second, i.first});
        }
        
        // start storing the chars in ans frequency wise
        string ans = "";
        while(!pq.empty()) {
            int freq = pq.top().first;  // frequency count
            char ch = pq.top().second;  // current char
            pq.pop();   // pop out the element
            
            // store the curr char (freq * 1 times)
            for(int i = 0; i < freq; i++) {
                ans += ch;
            }
        }
        
        return ans;
    }
};