class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> temp;
        
        for(int i=0; i<n; i++) {
            temp.push_back(nums1[i]);
        }
        
        for(int i=0; i<m; i++) {
            temp.push_back(nums2[i]);
        }
        
        sort(temp.begin(), temp.end());
        
        int s = temp.size();
        
        return (s % 2) ? temp[s / 2] : (temp[s/2 - 1] + temp[s/2]) / 2.0;
    }
};