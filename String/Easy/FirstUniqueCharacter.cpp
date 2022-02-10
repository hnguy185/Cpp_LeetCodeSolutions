/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0

Example 2:

Input: s = "loveleetcode"
Output: 2

Example 3:

Input: s = "aabb"
Output: -1

 
Constraints:

    1 <= s.length <= 105
    s consists of only lowercase English letters.

*/

/* Approach:
    1)We must maintain the occurences of each and every elements in the string. An array of
      size 26 can be used here OR a map for that matter
    2)To determine which char we are processing, use ASCII value to subtract
      said char to the value of 'a'
       Ex: 'c' is 99 and 'a' is 97, c - a = 99 - 97 = 2 so we use index 2 for char 'c'
    3)Traverse the string again and check the first occurence to see if it is equal to 1
       then return the index. Else return -1 because all the occurences are equal.

*/


class Solution {
public:
    int firstUniqChar(string s) {
        //declare a size 26 occurence array and initialize with 0s
        int occurences[26] = { 0 };

        //traverse the string to get the occurrences
        for (int i = 0; s[i] != NULL; i++) {
            occurences[s[i] - 'a']++;
        }

        //traverse to find the first unique char and return its index
        for (int i = 0; s[i] != NULL; i++) {
            if (occurences[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};