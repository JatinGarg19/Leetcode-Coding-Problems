class Solution {
public:
    // BRUTE FORCE APPROACH
    /*
    double solve(vector<int>& nums1, vector<int>& nums2) {
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
    */
    
    double usingBinarySearch(vector<int> nums1, vector<int> nums2, int m, int n) {
        if(m > n) {
            return usingBinarySearch(nums2, nums1, n, m);
        }
        
        int low = 0; 
        int high = m; 
        int medianPos = ((n + m) + 1)/2;
        
        while(low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = medianPos - cut1;
            
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            
            if(l1 <= r2 && l2 <= r1) {
                if((m + n) % 2 != 0) {
                    return max(l1,l2);
                }
                else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            
            else if(l1 > r2) high = cut1 - 1;
            
            else low = cut1 + 1;
        }
        
        return 0.0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // BRUTE FORCE SOLUTION
        //return solve(nums1, nums2);  // Tc - O(N) + O(N) + O(LOG(N+M)) , SC - O(N+M).
        
        int m = nums1.size();
        int n = nums2.size();
        
        return usingBinarySearch(nums1, nums2, m, n);
    }
};