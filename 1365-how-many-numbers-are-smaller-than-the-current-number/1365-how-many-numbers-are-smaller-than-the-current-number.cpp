class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> arr = nums;
        
        unordered_map<int,int> map;
        
        sort(arr.begin() , arr.end());
        
        for(int i = 0; i < arr.size(); i++) {
            if(map.find(arr[i]) == map.end()) {
                map[arr[i]] = i;
            }
        }
        
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = map[nums[i]];
        }
        
        return nums;
    }
};