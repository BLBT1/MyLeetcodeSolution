/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        // base case:
        if (x == 1 || n == 0)
            return 1;
        if (n == 1)
            return x;

        // use -(pow+1) to avoid MIN_Val case
        if (n < 0)
            return 1 / (x * myPow(x, -(n + 1)));

        double res = 1;
        while (n != 0)
        {
            if (n % 2 == 1)
                res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }
};
// @lc code=end
