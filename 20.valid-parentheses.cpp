/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> Stack;
        for (int i = 0; i < s.size(); ++i)
        {

            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                Stack.push(s[i]);
            }
            else if (Stack.empty())
            {
                return false;
            }
            else if (s[i] == ')')
            {
                if (Stack.top() != '(')
                    return false;
                Stack.pop();
            }
            else if (s[i] == '}')
            {
                if (Stack.top() != '{')
                    return false;
                Stack.pop();
            }
            else if (s[i] == ']')
            {
                if (Stack.top() != '[')
                    return false;
                Stack.pop();
            }

        } //for

        return Stack.empty();
    }
};
// @lc code=end
