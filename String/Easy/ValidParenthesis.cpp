/*
* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.

===================================================================================================================================
/* Approach:
        1)Use a stack to push all the left parens
        2)When a right parens is seen, pop the corresponding left paren in the stack. If mismatched parens then return false right away
        3)if the stack is empty, return true else false

        exp:()[]{} true
            ([)] false
*/

#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        char token, top;

        for (int i = 0; s[i] != NULL; i++)
        {
            token = s[i];

            //store all the left parens
            if (token == '(' ||
                token == '{' ||
                token == '[')
                stack.push(token);

            else
            {
                if (!stack.empty())
                {
                    top = stack.top();

                    //compare the left and the right paren in order to pop the stack or not
                    if ((token == ')' && top == '(') ||
                        (token == '}' && top == '{') ||
                        (token == ']' && top == '['))
                        stack.pop();
                    //return false right away because the open brackets must be closed in the correct order
                    else
                        return false;
                }
                //stack is empty but there are more right parens so return false right away
                else
                    return false;
            }
        }

        if (stack.empty())
            return true;
        return false;

    }
};
