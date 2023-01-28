class SummaryRanges {
    vector<vector<int>> data;
    
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        vector<int> interval{value, value};
        if (data.empty()) {
            data.push_back(interval);
            return;
        }
        
        int i = 0;
        for (; i < data.size(); ++i)
            if (data[i][0] > value) 
                break;
        
        if (i == 0) {
          if (value + 1 == data[i][0]) 
              data[i][0] = value;
          else 
              data.insert(data.begin(), interval);
        } 
        else {
          if (i == data.size()) {
            if (data[i - 1][1] + 1 == value) 
                data[i - 1][1] = value;
            else if (data[i - 1][1] < value) 
                data.push_back(interval);
          } 
          else {
            if (data[i - 1][1] < value) {
              if (data[i - 1][1] + 1 == value) {
                if (data[i][0] == value + 1) {
                  data[i - 1][1] = data[i][1];
                  data.erase(data.begin() + i);
                } 
                else {
                  data[i - 1][1] = value;
                }
              } 
              else {
                if (data[i][0] == value + 1) 
                    data[i][0] = value;
                else 
                    data.insert(data.begin() + i, interval);
              }
            }
          }
        }
    }
    
    vector<vector<int>> getIntervals() {
        return data;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */