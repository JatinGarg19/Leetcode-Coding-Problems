class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // This cond'n will be true only if the strings have a gcd.
        //Both the strings are made of same substring added multiple times.
        // Since they are multiples, next step is simply to find the gcd of the lengths of 2 strings e.g.               gcd(6,3) = 3, (we can use gcd function to find that)and get the substring of length 3 from either             str1 or str2.
        // In c++ it will be str1.substr(0, gcd).
        
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(size(str1), size(str2))) : "";
    }
};