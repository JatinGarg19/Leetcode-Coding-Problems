class Solution {
    public int lengthOfLastWord(String s) {
        int length = 0;
        
        for(int i = s.length() - 1; i >= 0; i--) {
            // char at i is not a space, means we found a word.
            if(s.charAt(i) != ' ') {
                length++;
            } else {
                // Check whether the space is between the words or at the end.
                if(length > 0) return length;
            }
        }
        
        return length;
    }
}