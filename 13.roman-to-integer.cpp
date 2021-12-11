/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'I')
            {
                if (i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                    res -= 1;
                else
                    res += 1;
            }
            else if (s[i] == 'V')
                res += 5;
            else if (s[i] == 'X')
            {
                if (i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                    res -= 10;
                else
                    res += 10;
            }
            else if (s[i] == 'L')
                res += 50;
            else if (s[i] == 'C')
            {
                if (i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M'))
                    res -= 100;
                else
                    res += 100;
            }
            else if (s[i] == 'D')
                res += 500;
            else if (s[i] == 'M')
                res += 1000;
        } //for
        return res;
    }
};
// @lc code=end
//s = "MCMXCIV"
//               i
//