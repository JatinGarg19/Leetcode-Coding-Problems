class Solution {
    public String convertToTitle(int columnNumber) {
        // Create an empty string for storing the characters.
        StringBuilder columnTitle = new StringBuilder();
        
        // Run a while loop while columnNumber is positive.
        while(columnNumber > 0) {
            // Subtract 1 from columnNumber;
            columnNumber--;
            
            // Get curr char by doing colNum % 26 + 'A'
            char c = (char)(columnNumber % 26 + 'A');
            
            // Divide columnNumber / 26.
            columnNumber /= 26;
            
            // append the output.
            columnTitle.append(c);
        }
        
        // Reverse the output bcz we have found characters from right to left.
        columnTitle.reverse();
        
        // Return the reversed string.
        return columnTitle.toString();
    }
}