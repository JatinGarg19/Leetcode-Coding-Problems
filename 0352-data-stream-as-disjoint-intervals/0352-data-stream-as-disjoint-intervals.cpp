class SummaryRanges {
    // set to store the addNumbers.
    set<int> values;
    
public:
    SummaryRanges() { }
    
    void addNum(int value) {
        // whatever value is there, push onto the set
        values.insert(value);  // Tc - O(logn)
    }
    
    vector<vector<int>> getIntervals() {    // Tc - O(N)
        // If our container is empty, we return empty vector.
        if(values.empty())
            return {};
        
        // answer array
        vector<vector<int>> intervals;
        
        // Starting interval initialization
        int left = -1, right = -1;
        
        for(int value : values) {
            // Update left and right with the 1st value that comes
            if(left < 0) {
                left = right = value;
            }
            
            // If right + 1 becomes = value, update right
            else if(value == right + 1) {
                right = value;
            }
            
            // else push interval into ans array and update left and right
            else {
                intervals.push_back({left, right});
                left = right = value;
            }
        }
        
        intervals.push_back({left, right});   // Tc - O(logn) + O(n) , SC - O(N)
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */