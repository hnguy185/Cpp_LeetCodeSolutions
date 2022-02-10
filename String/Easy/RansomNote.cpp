/*
* Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

 

Constraints:

    1 <= ransomNote.length, magazine.length <= 105
    ransomNote and magazine consist of lowercase English letters.

=========================================================================================================================
Approach:
    1)If the ransomeNote size > magazine size then return false right away
    2)We need to keep track of frequencies of each and every char in ransom note and
      magazine note
    3)To determine which char we are processing, use ASCII value to subtract
      said char to the value of 'a'
       Ex: 'c' is 99 and 'a' is 97, c - a = 99 - 97 = 2 so we use index 2 for char 'c'
    4)If the frequency of any char the ransom note is bigger than frequency of any char in
      the magazine then we can return false, else true

   Alternative:
    a)If the ransomeNote size > magazine size then return false right away
    b)Count the occurrences of the char in the magazine using a container (array)
    c)We decrease the count of any char in the array in step 2
      when we encounter said char in the ransom note
    d)Now check the frequency array for any negative, if there is the return false,
      else true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length())
            return false;

        int fRansom[26] = { 0 };
        int fMagazine[26] = { 0 };

        //tranverse the 2 string to keep track of the frequences
        for (int i = 0; ransomNote[i] != NULL; i++) {
            fRansom[ransomNote[i] - 'a']++;
        }

        for (int i = 0; magazine[i] != NULL; i++) {
            fMagazine[magazine[i] - 'a']++;
        }


        //traverse 2 frequency arrays to find if the frequency of char in the ransom note is bigger than the frequency of any char in the magazine then we can return false

        for (int i = 0; ransomNote[i] != NULL; i++) {
            if (fRansom[ransomNote[i] - 'a'] > fMagazine[ransomNote[i] - 'a'])
                return false;
        }
        return true;
    }
};