/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int t = x ^ y;
        int cnt = 0;
        while (t)
        {
            cnt += t & 1;
            t = t >> 1;
        }
        return cnt;
    }
};
// @lc code=end
