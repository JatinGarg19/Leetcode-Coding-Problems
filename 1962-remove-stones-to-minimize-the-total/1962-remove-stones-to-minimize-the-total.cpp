class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        
        while(k > 0) {
            int top = pq.top();
            pq.pop();
            
            int floorValue = floor(top / 2);
            top -= floorValue;
            
            pq.push(top);
            k--;
        }
        
        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};