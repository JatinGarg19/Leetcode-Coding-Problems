class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int h) {
        // TEMPORARY ARRAY
        vector<int> temp;
        
        // STARTING INDEX OF LEFT HALF OF ARRAY
        int left = l;
        
        // STARTING INDEX OF RIGHT HALF OF ARRAY
        int right = mid + 1;
        
        // STORING ELEMENTS IN A TEMP ARRAY IN A SORTED MANNER
        while(left <= mid && right <= h) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        
        // IF ELEMENTS ON THE LEFT HALF ARE STILL LEFT
        while(left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        
        // IF ELEMENTS ON RIGHT HALF ARE STILL LEFT
        while(right <= h) {
            temp.push_back(nums[right]);
            right++;
        }
        
        // TRANSFERRING ALL ELEMENTS FROM TEMP TO NUMS
        for(int i = l; i <= h; i++) {
            nums[i] = temp[i - l];
        }
    }
    
    void mergeSort(vector<int> &nums, int l, int h) {
        if(l >= h) return;
        
        int mid = l + (h - l) / 2;
        
        // LEFT HALF
        mergeSort(nums, l, mid);
        
        // RIGHT HALF
        mergeSort(nums, mid + 1, h);
        
        // MERGE BOTH THE SORTED HALVES
        merge(nums, l, mid, h);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        
        mergeSort(nums, 0, nums.size() - 1);
        
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);
        }
        
        return ans;
    }
};