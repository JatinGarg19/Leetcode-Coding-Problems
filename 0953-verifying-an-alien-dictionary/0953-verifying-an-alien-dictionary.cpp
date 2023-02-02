class Solution {
    unordered_map<char,char> mp;
    
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // mapping order string with abcde......z
        for(int i = 0; i < size(order); i++)
            mp[order[i]] = i + 'a';
        
        // Iterate over words array.
        for(auto& word : words) {
            // Iterate over particular word.
            for(auto& c : word) c = mp[c];
        }
        
        // is_sorted function is used to check if elements in a range are sorted.
        return is_sorted(begin(words), end(words));
    }
};