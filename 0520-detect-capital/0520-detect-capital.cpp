class Solution {
public:
    bool detectCapitalUse(string word) {
        // If only 1 letter, its always true.
        if(word.length() == 1) return true;
        
        // Maintain a count, run a for loop and increment count if letter is a cap.
        int count = 0;
        
        for(int i = 0; i < word.length(); i++) {
            if(isupper(word[i])) {
                count++;
            }
        }
        
        // If count is 1 and the 1st letter is capital, word is right.
        if(count == 1 && isupper(word[0])) return true;
        
        // If all letters are small or all capital, word is right
        if(count == 0 || count == word.length()) return true;
        // else return false.
        else return false;
    }
};