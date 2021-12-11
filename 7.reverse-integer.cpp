/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        if (x == INT_MIN)
            return 0;

        int sign = 1;
        if (x < 0)
            sign = -1;

        x = abs(x);

        int res = 0;
        while (x > 0)
        {
            // avoid int overflow
            if (res > INT_MAX / 10)
                return 0;
            if (res * 10 > INT_MAX - x % 10)
                return 0;

            res = res * 10 + x % 10;
            x = x / 10;
        }

        return res * sign;
    }
};
// @lc code=end
