class Solution {
public:
    int countOdds(int low, int high) {
        int odd_bw_1_and_low_minus_1 = low / 2;
        
        int odd_bw_1_and_high = (high + 1) / 2;
        
        return (odd_bw_1_and_high - odd_bw_1_and_low_minus_1);
    }
};