class Solution {
    vector<int> headChar;
public:
    int find(int x) {
        if(headChar[x] == -1) return x;
        
        return headChar[x] = find(headChar[x]);
    }
    
    void unionFunc(int x, int y) {
        int parentx = find(x);
        int parenty = find(y);
        
        if(parentx == parenty) return;
        
        // Make smaller one parent of the other, if parents are different
        headChar[max(parentx, parenty)] = min(parentx, parenty);
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        headChar.resize(26, -1);
        // Make group union
        for(int i = 0; i < s1.size(); i++) {
            unionFunc(s1[i] - 'a', s2[i] - 'a');
        }
        
        // Traverse in the basestr and find the parent of each char
        for(int i = 0; i < baseStr.size(); i++) {
            baseStr[i] = find(baseStr[i] - 'a') + 'a';
        }
        
        return baseStr;
    }
};