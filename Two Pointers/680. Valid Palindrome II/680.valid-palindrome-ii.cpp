/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                ++l;
                --r;
            }
            else
            {
                return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            }
        }
        return true;
    }

    bool isPalindrome(string &s, int begin, int end)
    {
        int l = begin, r = end;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                ++l;
                --r;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
