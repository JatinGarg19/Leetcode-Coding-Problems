class Solution {
public:
    string solve(string a , string b) {
        if(a.size() > b.size())
            return solve(b , a);
        
        int diff = b.size() - a.size();
        
        string padding;
        for(int i = 0; i < diff; i++) {
            padding.push_back('0');
        }
        
        a = padding + a;
        
        string res;
        char carry = '0';
        
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] == '1' && b[i] == '1') {
                if(carry == '1')
                    res.push_back('1') , carry = '1';
                else 
                    res.push_back('0') , carry = '1';
            }
            
            else if(a[i] == '0' && b[i] == '0') {
                if(carry == '1')
                    res.push_back('1') , carry = '0';
                else 
                    res.push_back('0') , carry = '0';
            }
            
            else if(a[i] != b[i]) {
                if(carry == '1')
                    res.push_back('0') , carry = '1';
                else 
                    res.push_back('1') , carry = '0';
            }
        }
        
        if(carry == '1')
            res.push_back(carry);
        
        reverse(res.begin() , res.end());
        
        int idx = 0;
        while(idx + 1 < res.size() && res[idx] == '0')
            idx++;
        
        return res.substr(idx);
    }
    
    string addBinary(string a, string b) {
        return solve(a , b);
    }
};