class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int> words_map;
        
        for(string word : words)
            words_map[word]++;
        
        vector<string> result;
        
        for(string word : words) {
            int n = word.size();
            
            vector<int> dp(n + 1, 0);
            
            dp[0] = 1;
            
            for(int i = 0; i < n; i++) {
                if(!dp[i])
                    continue;
                
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && words_map[(word.substr(i, j - i))] > 0){
                        dp[j] = 1;
                    }
                }
                
                if (dp[n]) {                  
                    result.push_back(word);
                    break;
                }
            }
        }
        
        return result;
    }
};