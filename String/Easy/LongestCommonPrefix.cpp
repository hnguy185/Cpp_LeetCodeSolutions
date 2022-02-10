/*
* Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.

========================================================================================================
/*Approach
    Using sort: Since std::sort will sort the string array in alphabetical order, we only need to find out the longest common prefix between the first and last word
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //check the size and return "" right away if the list of string is empty
        if (strs.size() == 0) {
            return "";
        }

        string res = "";
        //sort the string array
        sort(strs.begin(), strs.end());

        string first = strs[0]; // first word
        string last = strs[strs.size() - 1];// last word

        int shortestWordSize = first.size();

        // find out the longest common prefix between first and last word
        for (int i = 0; i < shortestWordSize; i++) {
            if (first[i] == last[i]) {
                //append the char to the result string
                res += first[i];
            }
            else
                break;
        }
        return res;
    }
};
