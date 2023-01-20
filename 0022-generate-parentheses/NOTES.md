Approach 1: To form all the sequences of balanced bracket subsequences with n pairs. So there are n opening brackets and n closing brackets.
So the subsequence will be of length 2*n. There is a simple idea, the i’th character can be ‘{‘ if and only if the count of ‘{‘ till i’th is less than n and i’th character can be ‘}’ if and only if the count of ‘{‘ is greater than the count of ‘}’ till index i. If these two cases are followed then the resulting subsequence will always be balanced.
So form the recursive function using the above two cases.
​
Algorithm:
​
Create a recursive function that accepts a string (s), count of opening brackets (o) and count of closing brackets (c) and the value of n.
if the value of opening bracket and closing bracket is equal to n then print the string and return.
If the count of opening bracket is greater than count of closing bracket then call the function recursively with the following parameters String s + “}”, count of opening bracket o, count of closing bracket c + 1, and n.
If the count of opening bracket is less than n then call the function recursively with the following parameters String s + “{“, count of opening bracket o + 1, count of closing bracket c, and n.
​
​