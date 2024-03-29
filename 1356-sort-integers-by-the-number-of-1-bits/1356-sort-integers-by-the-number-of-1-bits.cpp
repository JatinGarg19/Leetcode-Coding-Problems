class Solution {
public:
    static int numberOf1s(int x) {
        int count = 0;
        while(x) {
            x = x & (x - 1);
            count++;
        }
        
        return count;
    }
    
    static bool compare(int a, int b) {
        int p = numberOf1s(a);
        int q = numberOf1s(b);
        
        if(p == q) {
            return (a <= b);
        } else {
            return (p < q);
        }
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};