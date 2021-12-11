/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int temp = x;
        if (x < 0)
            return false;
        long reverseNum = 0;
        while (x != 0)
        {
            int digit = x % 10;
            x /= 10;
            reverseNum = reverseNum * 10 + digit;
        }

        return reverseNum == temp;
    }
};
// @lc code=end
