/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 1;
        int r = x;
        while (l < r)
        {
            int mid = l + (r - l + 1) / 2;
            if (mid > x / mid)
            {
                r = mid - 1;
            }
            else
            {
                l = mid;
            }
        }
        if (l <= x / l)
            return l;
        return r;
    }
};
// @lc code=end
