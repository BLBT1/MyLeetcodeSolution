/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

// @lc code=start
class Solution
{
public:
    int maxPower(string s)
    {
        int i = 0;
        int res = 1;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[i] != s[j])
            {
                i = j;
            }
            res = max(j - i + 1, res);
        }
        return res;
    }
};
// @lc code=end
