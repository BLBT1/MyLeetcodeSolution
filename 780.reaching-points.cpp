/*
 * @lc app=leetcode id=780 lang=cpp
 *
 * [780] Reaching Points
 */

// @lc code=start
class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        if (sx > tx || sy > ty)
            return false;

        if (sx == tx)
            return (ty - sy) % tx == 0;
        else if (sy == ty)
            return (tx - sx) % ty == 0;

        if (tx < ty)
            return reachingPoints(sx, sy, tx, ty - tx);
        else if (tx > ty)
            return reachingPoints(sx, sy, tx - ty, ty);
        else
            return false;
    }
};
// @lc code=end
