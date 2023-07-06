class StockSpanner {
    // Push every pair of <price, result> to stack.
    stack<pair<int,int>> st;
    
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int result = 1;
        
        // if stack is not empty and st.top..first <= price, add to result and pop.
        while(!st.empty() && st.top().first <= price) {
            result += st.top().second;
            st.pop();
        }
        
        // if stack is empty, push pair of <price, result>.
        st.push({price, result});
        
        return result; // TC - Amortized O(1) - O(1) mostly but in very few cases its O(n)
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */