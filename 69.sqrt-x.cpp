/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int a)
    {
        if (a <= 1)
            return a;
        // f(x) = x^2 - a, find root of f(x)
        // Newton's method
        // f'(x) = 2x
        // x' = x - f(x) / f'(x) = x - (1/2*x - a/(2*x))
        //    = (x + a / x) / 2
        int x = a;
        while (x > a / x)
            x = (x + a / x) / 2;
        return x;
    }
};
// @lc code=end
