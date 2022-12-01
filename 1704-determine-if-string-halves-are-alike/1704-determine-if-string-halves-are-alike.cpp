class Solution {
public:
    bool halvesAreAlike(string s) {
        int vowelCount1 = 0;
        int vowelCount2 = 0;
        
        for(int i = 0; i < s.length()/2; i++) {
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or
               s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
            {
                vowelCount1++;
            }
        }
        
        for(int i = s.length()-1; i >= s.length()/2; i--) {
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u' or
               s[i]=='A' or s[i]=='E' or s[i]=='I' or s[i]=='O' or s[i]=='U')
            {
                vowelCount2++;
            }
        }
        
        return vowelCount1 == vowelCount2;
    }
};