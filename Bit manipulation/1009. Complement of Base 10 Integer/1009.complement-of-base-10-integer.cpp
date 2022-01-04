/*
 * @lc app=leetcode id=1009 lang=cpp
 *
 * [1009] Complement of Base 10 Integer
 */

// @lc code=start
class Solution
{
public:
    int bitwiseComplement(int n)
    {
        int x = 1;
        // find the 1111...111 with the fit length
        while (n > x)
        {
            x = x * 2 + 1; // 1 -> 11 -> 111 -> ...
        }

        return n ^ x;
    }
};
// @lc code=end

// 1111
// 0100

//-> 1011 => this is the complement of 0100