/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int count = 0;
        int res = 0;
        for (char ch : s)
        {
            if (ch == '(')
                count++;
            else if (ch == ')')
                count--;

            if (count < 0)
            {
                count++;
                res++;
            } // if
        }     //for

        return count + res;
    }
};
// @lc code=end
