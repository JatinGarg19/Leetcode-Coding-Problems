class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        
        for(int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }
        
        for(auto &i : counts) {
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        vector<int> result;
        while(k--) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};