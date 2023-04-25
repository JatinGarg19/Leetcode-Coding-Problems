class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // to store elements in the decreasing order in the heap
        priority_queue<int> pq(stones.begin(), stones.end());
        
        // loop till there is more than 1 element
        while(pq.size() > 1) {
            // max element
            int y = pq.top(); pq.pop();
            // second max element
            int x = pq.top(); pq.pop();
            
            if(x != y) pq.push(y - x);
        }
        
        return pq.empty() ? 0 : pq.top();   // Tc - O(nlogn) , Sc - O(n).
    }
};