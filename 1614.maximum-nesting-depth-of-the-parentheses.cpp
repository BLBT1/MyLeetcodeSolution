/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

// @lc code=start
class Solution
{
    // use idea of stack w/o a stack
public:
    int maxDepth(string s)
    {
        int res = 0;
        int tmp = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                tmp += 1;
                res = max(res, tmp);
            } // if
            else if (s[i] == ')')
            {
                tmp -= 1;
            } //else
        }     //for
        return res;
    }
};
// @lc code=end
