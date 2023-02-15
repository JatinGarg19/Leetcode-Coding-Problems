class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        
        unordered_map<char,int> map;
        
        for(int i = 0; i < jewels.size(); i++) {
            map[jewels[i]] = i;
        }
        
        for(int j = 0; j < stones.size(); j++) {
            if(map.find(stones[j]) != map.end()) {
                count++;
            }
        }
        
        return count;
    }
};