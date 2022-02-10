/*
* A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

 

Constraints:

    1 <= s.length <= 2 * 105
    s consists only of printable ASCII characters.

=====================================================================================================================================
/*Approach: using 2 pointers
    1) Check if the size of the string is 0 then return true right away
    2) Iterate the 1st pointer starting for left and 2nd pointer starting from right. Check if they are either a digit or a letter.
       If they are then transform them to a lower case, else ignore and proceed
    3) Compare the 2 pointers, proceed if they are the same else return false.
    Notes:
     isalnum checks whether c is either a decimal digit or an uppercase or lowercase letter.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0)
            return true;

        //set 2 pointers
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            if (isalnum(s[l]))
                s[l] = tolower(s[l]);
            if (isalnum(s[r]))
                s[r] = tolower(s[r]);
            if (!isalnum(s[l]))
                l++;
            else if (!isalnum(s[r]))
                r--;
            else if (s[l] != s[r])
                return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};
