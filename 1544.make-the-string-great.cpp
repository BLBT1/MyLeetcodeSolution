/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

// @lc code=start
class Solution
{
public:
    string makeGood(string s)
    {
        // 使用stack的思维，但是不一定需要stack

        if (s.size() <= 1)
            return s;

        string res;
        for (char c : s)
        {
            int diff = 'a' - 'A';
            if (res.size() &&
                abs(res.back() - c) == diff)
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};
// @lc code=end
