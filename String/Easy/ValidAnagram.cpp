/*
* Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

 

Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

 ===========================================================================================================================================================
 Approach
    1) If the 2 strings dont have the same size then return false right away

    2) Use an array of size 26, init with 0s because we are only dealing with lower case letters, and increase the count of the chars when we encounter them in the first string.
    BUT we decrease the count of the char when we encounter it in the second string

    3) Scan the array, if the value of each index is 0 then return true else false
    Note:
       To determine which char we are processing, use ASCII value to subtract
          said char to the value of 'a'
       Ex: 'c' is 99 and 'a' is 97, c - a = 99 - 97 = 2 so we use index 2 for char 'c'
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;


        int freq[26] = { 0 };

        //count the occurences in the first string
        for (int i = 0; s[i] != NULL; i++) {
            freq[s[i] - 'a']++;
        }

        //decrease the occurences when we encounter the char in the second string
        for (int i = 0; t[i] != NULL; i++) {
            freq[t[i] - 'a']--;
        }

        //scan for any negative elem
        for (auto value : freq) {
            if (value != 0)
                return false;
        }
        return true;

    }
};