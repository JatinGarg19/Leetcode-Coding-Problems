class Solution {
public:
    int solve(vector<int>& height, int n) {
        // left pointer
        int left = 0;
        
        // right pointer
        int right = n - 1;
        
        // area to find maximum amount of water a container can store.
        int area = 0;
        
        // Iterate till left ptr is less than right ptr
        while(left < right) {
            area = max(area, min(height[left],height[right]) * (right - left));
            
            if(height[left] < height[right])
                left = left + 1;
            else
                right = right - 1;
        }
        
        return area;
    }
    
    int maxArea(vector<int>& height) {
        int n = height.size();
        return solve(height, n);
    }
};