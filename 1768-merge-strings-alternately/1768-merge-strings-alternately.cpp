class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        int i = 0, j = 0;
        string s = "";
        
        while(i < n1 && j < n2) {
            s.push_back(word1[i]);
            i++;
            s.push_back(word2[j]);
            j++;
        }
        
        while(i < n1) {
            s.push_back(word1[i]);
            i++;
        }
        
        while(j < n2) {
            s.push_back(word2[j]);
            j++;
        }
        
        return s;
    }
};