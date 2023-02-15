class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // Maintain count of stones that are jewels. 
        int count = 0;
        
        // HashTable - char , idx pair.
        unordered_map<char,int> map;
        
        // Push characters of jewels into the map.
        for(int i = 0; i < jewels.size(); i++) {
            map[jewels[i]] = i;
        }
        
        for(int j = 0; j < stones.size(); j++) {
            // If the corresponding stone is a jewel, increment the counter.
            if(map.find(stones[j]) != map.end()) {
                count++;
            }
        }
        
        // return answer.
        return count;
    }
};