/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        // 这题很巧妙啊hhh
        int prev = 0;
        int curr = 1;
        int res = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                curr++;
            }
            else
            {
                prev = curr;
                curr = 1;
            }

            if (prev >= curr)
                ++res;
        }

        return res;
    }
};
// @lc code=end
//s = "0 0 1 1 0 0 1 1"
//