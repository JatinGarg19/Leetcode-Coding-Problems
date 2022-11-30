class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Intialize maximum profit as 0.
        int maxPro = 0;
        // And initialize minPrice as the maximum
        int minPrice = INT_MAX;

        for(int i = 0; i < prices.size(); i++) {
            // minPrice will be minimum of minPrice and price at that index
            minPrice = min(minPrice, prices[i]);
            // maxi prof will be maximum of maxpro and price - minprice.
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
    }
};