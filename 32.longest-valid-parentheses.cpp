/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() < 2)
            return 0;

        stack<int> Stack;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                Stack.push(i);
            else
            {
                if (!Stack.empty() &&
                    s[Stack.top()] == '(')
                {
                    Stack.pop();
                    res = max(res,
                              i - (Stack.empty() ? -1 : Stack.top()));
                } //if
                else
                {
                    Stack.push(i);
                } //else
            }     //else
        }         //for

        return res;
    }
};
// @lc code=end
